#pragma once

#ifndef PCB_H
#define PCB_H

#include "PageTable.h"

class PCB
{
	public:
		PCB();
		~PCB();
		PCB(int PID);
		int getPID() const;
		int getSize() const;
		void printPageTable() const;



	private:
		int PID;
		int size;
		PageTable* pageTable;
};

#endif