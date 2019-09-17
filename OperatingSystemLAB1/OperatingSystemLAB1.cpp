// OperatingSystemLAB1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//@author John Ong SID 015529031

#pragma once
#include <iostream>
#include "PCB.h"
#include "PageTable.h"

using namespace std;

void insertPCB(PCB* current, PCB* insert) 
{
	if (current->getNext() == NULL)
	{
		current->setNext(insert);
		insert->setPrevious(current);
	}
	else {
		insertPCB(current->getNext(), insert);
	}
}

void printReadyQueue(PCB* current)
{
	if (current->getNext() == NULL)
	{
		cout << "End of ready Queue" << endl;
	}
	else
	{
		cout << current->getPID() << endl;
		printReadyQueue(current->getNext());
	}

}

int main()
{
	cout << "\nHello! This is the Operating System Simulator." << endl;
	bool run = 1;

	int PID_Global = 1000; //Arbitrary global variable that will be used for the PID numbers to jump off of.
	PCB* ReadyQueue = NULL;

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
					if (ReadyQueue == NULL)
					{
						ReadyQueue = &currentPCB;
						currentPCB.setPrevious(ReadyQueue);
					}
					else
					{
						insertPCB(ReadyQueue, &currentPCB);
					}
					cout << "End of bit flip" << endl;
					currentPageTable.printIndexes();
					printReadyQueue(ReadyQueue);
				}
				else
				{
					cout << "Not enough free space was found. Terminating process" << endl;
				}
				
			}
	}
	cout << "Done" << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
