#pragma once

#ifndef PCB_H
#define PCB_H

#include "PageTable.h"

using namespace std;

class PCB
{
	public:
		PCB();
		~PCB();
		PCB(int inPID);
		int getPID() const;
		int getSize() const;
		void printPageTable();
		void setPageTable(PageTable* inPT);



	private:
		int PID;
		int size;
		PageTable* pageTable;
};

#endif