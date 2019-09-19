#pragma once

#ifndef READYQUEUE
#define READYQUEUE

#include <iostream>
#include "PCB.h"

using namespace std;

class ReadyQueue
{
	public:
		ReadyQueue();
		~ReadyQueue();
		bool find(int inPID);
		void insert(PCB* inPCB);
		void terminate(int inPID);
		void print();
		void printHead();

	private:
		PCB* head;
		PCB* tail;
};

#endif 
