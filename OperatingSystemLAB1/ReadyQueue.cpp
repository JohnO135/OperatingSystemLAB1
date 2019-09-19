#include "ReadyQueue.h"

ReadyQueue::ReadyQueue()
{
	head = NULL;
	tail = NULL;
}

ReadyQueue :: ~ReadyQueue()
{

}

bool ReadyQueue::find(int inPID)
{
	PCB* temp = head;
	if (temp == NULL)
	{
		return false;
	}
	else if (temp->getPID() == inPID)
	{
		return true;
	}
	else if (temp == tail && temp->getPID() != inPID)
	{
		return false;
	}

}

void ReadyQueue :: insert(PCB* inPCB)
{
	if (head == NULL)
	{
		head = inPCB;
		tail = inPCB;
	}
	else
	{
		tail->setNext(inPCB);
		tail = inPCB;
	}
}

void ReadyQueue :: terminate(int inPID)
{
	PCB* prev = head;
	PCB* temp = head;
	PCB* next = temp->getNext();
	if(temp->getPID() == inPID && temp == head)
	{
		head = temp->getNext();
	}
	while (temp != tail)
	{
		if (temp->getPID() == inPID)
		{
			prev->setNext(next);
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
	}
}

void ReadyQueue::print()
{
	PCB* temp = head;
	if(temp != tail)
	{
		cout << temp->getPID() << " is " << temp->getSize() << " blocks." << endl;
		temp = temp->getNext();
	}
	cout << temp->getPID() << " is " << temp->getSize() << " blocks." << endl;
}

void ReadyQueue::printHead()
{
	cout << " its next is " << head->getNext()->getPID() << endl;
}
