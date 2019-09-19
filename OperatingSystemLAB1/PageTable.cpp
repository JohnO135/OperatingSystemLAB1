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

void PageTable::printIndexes()
{
	for (int i = 0; i < indexes.size(); i++)
	{
		cout << indexes.at(i) << endl;
	}
}