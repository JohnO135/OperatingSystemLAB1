#pragma once

#ifndef PAGETABLE_H
#define PAGETABLE_H

class PageTable
{
	public: 
		PageTable();
		~PageTable();
		void setValue(int index);
		int getValue(int index) const;

	private:
		int indexes[];
};

#endif