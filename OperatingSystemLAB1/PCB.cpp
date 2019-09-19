#pragma once

#include "PCB.h"
#include "PageTable.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

//Default Constructor
PCB::PCB()
{
	srand(time(NULL));
	PID = 0;
	size = (rand() % 250) + 10;
	pageTable = NULL;
	next = NULL;
	//previous = NULL;
	

}

//PCB overload Constructor
PCB::PCB(int inPID)
{
	srand(time(NULL));
	PID = inPID;
	size = (rand() % 250) + 10;
	pageTable = NULL;
	next = NULL;
	//previous = NULL;
}

//Deconstructor
PCB::~PCB()
{

}

//Returns PID
int PCB :: getPID() const
{
	return PID;
}

//Returns size of the PCB
int PCB::getSize() const
{
	return size;
}

//Sets the pointer to a pagetable
void PCB::setPageTable(PageTable* inPT)
{
	pageTable = inPT;
}

//Returns the pagetable the pointer is pointing too
PageTable* PCB :: getPageTable()
{
	return pageTable;
}

//Prints the pagetable using the function within the PageTable class. Used for debug
void PCB::printPageTable()
{
	pageTable->printIndexes();
}


/*void PCB :: setPrevious(PCB* inPCB)
{
	previous = inPCB;
}*/

//sets the next pointer
void PCB :: setNext(PCB* inPCB)
{
	next = inPCB;

}


/*PCB* PCB :: getPrevious() const
{
	return previous;
}*/

//Returns the next pointer from the PCB
PCB* PCB :: getNext() const
{
	return next;
}