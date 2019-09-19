#include "ReadyQueue.h"

//Default Constructor
ReadyQueue::ReadyQueue()
{
	PID_Global = 1000;
	head = NULL;
	tail = NULL;
}

//Deconstructor
ReadyQueue :: ~ReadyQueue()
{

}

//Used to tell if a PCB exists within the queue
bool ReadyQueue::find(int inPID)
{
	PCB* temp = head;
	while (temp != tail)
	{
		if (temp == head && temp == NULL)
		{
			return false;
		}
		else if (temp->getPID() == inPID)
		{
			return true;
		}
		else
		{
			temp = temp->getNext();
		}
	}
	if (temp->getPID() == inPID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Creates PCB with unique PID, Creates a pagetable, Sets pointer to pagetable, determines if the PCB can fit within the MBT based off free blocks. if true inserts into queue and adjusts MBT free space int
void ReadyQueue :: insert(int &inMBTSize)
{
	PID_Global++;
	PCB* currentPCB = new PCB(PID_Global);
	PageTable* currentPageTable = new PageTable();
	currentPCB->setPageTable(currentPageTable);
	if (currentPCB->getSize() > inMBTSize)
	{
		cout << "Process' required blocks exceeds free blocks. Terminating process." << endl;
		delete currentPCB;
		delete currentPageTable;
	}
	else
	{
		inMBTSize -= currentPCB->getSize();
		if (head == NULL)
		{
			head = currentPCB;
			tail = currentPCB;
		}
		else
		{
			tail->setNext(currentPCB);
			tail = currentPCB;
		}
		cout << "Done adding" << endl;
	}
}

//Returns the pointer to a specified PCB. Used in conjunction with find()
PCB* ReadyQueue:: getPCB(int inPID)
{
	PCB* temp = head;
	while (temp != tail)
	{
		if (temp->getPID() == inPID)
		{
			return temp;
		}
		else
		{
			temp = temp->getNext();
		}
	}
	if (temp->getPID() == inPID)
	{
		return temp;
	}
	else
	{
		return NULL;
	}
}

//Returns the end of the queue
PCB* ReadyQueue::getTail()
{
	return tail;
}

//Used in order to remove a PCB from front, middle or end of queue. Used only after the MBT has been adjusted.
void ReadyQueue :: terminate(int inPID, int& inMBTSize)
{
	PCB* prev = head;
	PCB* temp = head;
	PCB* next = temp->getNext();
	if(temp->getPID() == inPID && temp == head)
	{
		head = temp->getNext();
		inMBTSize += temp->getSize();
		delete temp->getPageTable();
		delete temp;
	}
	while (temp != tail)
	{
		if (temp->getPID() == inPID)
		{
			prev->setNext(next);
			inMBTSize += temp->getSize();
			delete temp->getPageTable();
			delete temp;
		}
		else {
			prev = temp;
			temp = next;
			next = next->getNext();
		}
	}
	if (temp == tail && temp->getPID() == inPID)
	{
		prev->setNext(NULL);
		tail = prev;
		inMBTSize += temp->getSize();
		delete temp->getPageTable();
		delete temp;
	}
}

void ReadyQueue::terminateAll()
{
	PCB* temp = head;
	PCB* next;

	while (temp != NULL)
	{
		next = temp->getNext();
		delete temp;
		temp = next;
	}
}

//This print function uses the PCB object node to get the size as well as uses the pointer within the PCB to get the pagetable and access the functions within it such as retrieving indexes.
void ReadyQueue::print()
{
	PCB* temp = head;
	while(temp != tail)
	{
		cout << temp->getPID() << " is " << temp->getSize() << " blocks." << "This range is from blocks: " << temp->getPageTable()->getValue(0) << " to " << temp->getPageTable()->getValue(temp->getSize()-1) << endl;
		temp = temp->getNext();
	}
	cout << temp->getPID() << " is " << temp->getSize() << " blocks." << "This range is from blocks: " << temp->getPageTable()->getValue(0) << " to " << temp->getPageTable()->getValue(temp->getSize() - 1) << endl;
}

//Determines if the Ready Queue has any PCBs in it already. 
bool ReadyQueue :: isEmpty()
{
	if (head == NULL && tail == NULL)
	{
		return true;
	}
	if (tail != NULL && head == NULL)
	{
		tail == NULL;
		return true;
	}
	else {
		return false;
	}
}