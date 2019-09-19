#pragma once

#ifndef READYQUEUE
#define READYQUEUE

#include <iostream>
#include "PCB.h"
#include "PageTable.h"

using namespace std;

class ReadyQueue
{
	public:
		ReadyQueue();
		~ReadyQueue();
		bool find(int inPID);
		void insert(int &inMBTSize);
		void terminate(int inPID, int& inMBTSize);
		void print();
		bool isEmpty();
		PCB* getPCB(int inPID);
		PCB* getTail();

	private:
		int PID_Global;
		PCB* head;
		PCB* tail;
};

#endif 
