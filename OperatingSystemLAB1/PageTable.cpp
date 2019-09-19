#pragma once

#include "PageTable.h"

using namespace std;

//Default constructor
PageTable :: PageTable()
{
	
}

//Deconstructor
PageTable ::~PageTable()
{

}

//A way to append to end of vector
void PageTable:: add(int inValue)
{
	indexes.push_back(inValue);
}

//Recording the indexes of the process bits in use at specific indexes of the VECTOR
void PageTable::setValue(int inIndex, int inValue)
{
	indexes.at(inIndex) = inValue;
}

//returning index within the vecor of the Page Table
int PageTable::getValue(int index) const
{
	return indexes.at(index);
}

//Debug function used just for me to see that the indexes were saved after using the add function
void PageTable::printIndexes()
{
	for (int i = 0; i < indexes.size(); i++)
	{
		cout << indexes.at(i) << endl;
	}
}

//Returning the size. Used when the last index is needed to be reached from outside of the pageTable/PCB
int PageTable:: getSize()
{
	return sizeof(indexes);
}

//Returns the indexes vector for use when flipping back the blocks to free
vector<int> PageTable :: getVector()
{
	return indexes;
}