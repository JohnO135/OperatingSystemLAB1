#pragma once

#include "PCB.h"
#include "PageTable.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

PCB::PCB()
{
	srand(time(NULL));
	PID = 0;
	size = (rand() % 250) + 10;
	pageTable = NULL;
	next = NULL;
	previous = NULL;
	

}

PCB::PCB(int inPID)
{
	srand(time(NULL));
	PID = inPID;
	size = (rand() % 250) + 10;
	pageTable = NULL;
	next = NULL;
	previous = NULL;
}

PCB::~PCB()
{

}

int PCB :: getPID() const
{
	return PID;
}

int PCB::getSize() const
{
	return size;
}

void PCB::setPageTable(PageTable* inPT)
{
	pageTable = inPT;
}

PageTable* PCB :: getPageTable()
{
	return pageTable;
}

void PCB::printPageTable()
{
	pageTable->printIndexes();
}

void PCB :: setPrevious(PCB* inPCB)
{
	previous = inPCB;
}

void PCB :: setNext(PCB* inPCB)
{
	next = inPCB;

}

PCB* PCB :: getPrevious() const
{
	return previous;
}

PCB* PCB :: getNext() const
{
	return next;
}