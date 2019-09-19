// OperatingSystemLAB1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//@author John Ong SID 015529031

#pragma once
#include <iostream>
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

			if (userChoice == 4) //Will end program. Still needs implementation to terminate current processes.
			{
				run = 0;
			}

			if (userChoice < 1 || userChoice > 4)
			{
				cout << "\nNot a menu option. Try again.\n" << endl;
			}

			if (userChoice == 1) //Initiating a process
			{
				PID_Global++;
				PCB currentPCB = PCB(PID_Global);
				PageTable currentPageTable = PageTable();
				currentPCB.setPageTable(&currentPageTable);
				PCB* temp = &currentPCB;
				if (MBTsizeFree > currentPCB.getSize())
				{
					cout << "Enough free space is available" << endl;
					MBTsizeFree -= currentPCB.getSize();
					int FindBits = currentPCB.getSize();
					for (int i = 0; i < sizeof(MBT); i++)
					{
						if (MBT[i] == 0)
						{
							MBT[i] = 1;
							FindBits--;
							currentPageTable.add(i);
						}
						if (FindBits == 0)
						{
							break;
						}
					}
					RQ.insert(temp);
					cout << "Inserted PCB" << endl;
					cout << "End of block flip" << endl;
					//.printHead();
				}
				else
				{
					cout << "Not enough free space was found. Terminating process" << endl;
				}
				
			}
			
			if (userChoice == 2)
			{
				RQ.print();
			}
	}
	cout << "Done" << endl;
	return 0;
}
