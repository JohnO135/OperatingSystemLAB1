#pragma once

#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <vector>
#include <iostream>

using namespace std;

class PageTable
{
	public: 
		PageTable();
		~PageTable();
		void add(int inValue);
		void setValue(int inIndex, int inValue);
		int getValue(int index) const;
		void printIndexes();


	private:
		vector<int> indexes;
};

#endif