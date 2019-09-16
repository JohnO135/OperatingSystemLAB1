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
	indexes.append(inValue);
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