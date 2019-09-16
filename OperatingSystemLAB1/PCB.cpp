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
	size = rand() % 100 + 1;
	

}

PCB::PCB(int inPID)
{
	srand(time(NULL));
	PID = inPID;
	size = rand() % 100 + 1;
	pageTable = NULL;
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

void PCB::printPageTable()
{
	pageTable->printIndexes();
}
