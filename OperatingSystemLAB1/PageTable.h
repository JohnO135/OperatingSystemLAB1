#pragma once

#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <vector>
#include <iostream>

class PageTable
{
	public: 
		PageTable();
		~PageTable();
		void add(int inValue);
		void setValue(int inIndex, int inValue);
		int getValue(int index) const;

	private:
		vector<int> indexes;
};

#endif