// OperatingSystemLAB1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//@author John Ong SID 015529031

#pragma once
#include <iostream>
#include <cstdlib>
#include "PCB.h"
#include "PageTable.h"
#include "ReadyQueue.h"

using namespace std;


int main()
{
	cout << "\nHello! This is the Operating System Simulator." << endl;
	bool run = 1;

	int PID_Global = 1000; //Arbitrary global variable that will be used for the PID numbers to jump off of.

	//This code block will generate the MBT
	int MBTsizeFree = 1024 - 32; //32 represents the bits used for the Operating System
	cout << "Generating MBT..." << endl;
	bool MBT[1024];

	//Setting the MBT bits to false/or not in use
	for (int i = 0; i < sizeof(MBT); i++)
	{
		MBT[i] = 0;
	}

	//Flipping the bits for the OS
	cout << "Flipping OS bits..." << endl;
	for (int i = 0; i < 32; i++)
	{
		MBT[i] = 1;
	}

	//Instantiate a ready queue
	ReadyQueue RQ = ReadyQueue();

	while(run)
	{
			cout << "Your options are: \n1)Initiate a Process\n2)Print system state\n3)Terminate process with a specific PID\n4)Exit" << endl;
			int userChoice;
			cin >> userChoice;
			if (cin.fail()) //Checks to ensure the user enters an integer. If not cin is cleared and user is prompted again
			{
				cin.clear();
				cin.ignore();
				cout << "Not an integer please enter a valid input: " << endl;
				cin >> userChoice;
			}

			if (userChoice < 1 || userChoice > 4)
			{
				cout << "\nNot a menu option. Try again.\n" << endl;
			}

			if (userChoice == 1) //Initiating a process
			{
				int tempMBTsize = MBTsizeFree;//Temporarily saves current MBT
				RQ.insert(MBTsizeFree);
				if (MBTsizeFree != tempMBTsize)//Checks after the insert function to see if the MBTsize was adjusted(Meaning there was enough free blocks for a new process)
				{
					int findBlocks = RQ.getTail()->getSize();
					PageTable* tempPT = RQ.getTail()->getPageTable();
					for (int i = 0; i < sizeof(MBT); i++)
					{
						if (MBT[i] == 0)
						{
							MBT[i] = 1;
							findBlocks--;
							tempPT->add(i);
						}
						if (findBlocks == 0)
						{
							break;
						}
					}
				}
				cout << "End of block flip" << endl;
			}
			if (userChoice == 2)
			{
				//Prints out the blocks of the MBT
				for (int i = 0; i < sizeof(MBT); i++)
				{
					if ((i % 16) == 0 && (i % 64) != 0)
					{
						cout << " " << MBT[i];
					}
					else if ((i % 64) == 0)
					{
						cout << "\n" << MBT[i];
					}
					else
					{
						cout << MBT[i];
					}
				}
				cout << "\n\nReadyQueue: " << endl;
				if (RQ.isEmpty() == true)
				{
					cout << "Empty. First 32 blocks from 0 to 31 are for the OS" << endl;
				}
				else
				{
					RQ.print(); //Prints out the Ready Queue
				}
				
				cout <<  endl;
			}
			
			if (userChoice == 3)
			{
				cout << "\nReady Queue: " << endl;
				if (RQ.isEmpty() == true)
				{
					cout << "\nEmpty. First 32 blocks from 0 to 31 are for the OS\n" << endl;
				}
				else
				{
					RQ.print(); //Prints out the Ready Queue
					cout << "\nPlease enter the PID of the Process you would like to terminate: ";
					bool validIn = true;
					int userPID;
					cin >> userPID;
					if (cin.fail()) //Checks to ensure the user enters a valid INTEGER PID. If not cin is cleared and user is prompted again
					{
						cin.clear();
						cin.ignore();
						validIn = false;
						//This while loop prevents the script from crashing if a wrong input is given
						while (validIn == false)
						{
							cout << "Not a PID please enter a valid input (integer): " << endl;
							cin >> userChoice;
							if (cin.fail())
							{
								cin.clear();
								cin.ignore();
							}
							else {
								validIn = true;
							}
						}
						//This section now deals with terminating the chosen Process.
						if (RQ.find(userPID) == true)
						{

							RQ.terminate(userPID);
						}
						else
						{
							cout << "\nPCB with that PID was not found" << endl;
						}
					}
				}
				
			}

			if (userChoice == 4) //Will end program. Still needs implementation to terminate current processes.
			{
				run = 0;
			}
	}
	cout << "Done" << endl;
	return 0;
}
