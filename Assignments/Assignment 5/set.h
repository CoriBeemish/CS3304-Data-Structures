// FILE: set.h
// AUTHOR: Michael Main, Walter Savitch

#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>
#include "node1.h"

using namespace main_savitch_5;

class set
{
public:
	typedef node::value_type value_type;
	typedef std::size_t size_type;

	set();
	// postcondition: empty set has been created
	//Efficiency: O(1)

	~set();
	// postcondition: set has been deallocated
	//Efficiency: O(1)

	set(const set& source);
	// postcondition: a copy of source has been created
	//Efficiency: O(1)

	set& operator = (const set& source);
	// postcondition:
	//Efficiency: O(n)

	void insert(const value_type& entry);
	// postcondition: entry is in the set
	//Efficiency: O(1)

	void remove(const value_type& entry);
	// postcondition: entry is not in the set
	//Efficiency: o(1)

	size_type size() const;
	// postcondition: number of elements in the set has been returned
	//Efficiency: O(n)

	bool contains(const value_type& entry) const;
	// postcondition: whether entry is in the set has been returned
	//Efficiency: O(n)

	friend set set_union(const set& s1, const set& s2);
	//postcondition: union of s1 & s2 has been returned
	//Efficiency: O(n)

	friend set set_intersection(const set& s1, const set& s2);
	// postcondition: intersection of s1 & s2 has been returned
	//Efficiency: O(n)

	friend set set_difference(const set& s1, const set& s2);
	// postcondition: difference of s1 - s2 has been returned
	//Efficiency: O(n)

	friend bool is_subset(const set& s1, const set& s2);
	// postcondition: returned whether s1 is a subset of s2
	//Efficiency: O(n)

	friend bool operator == (const set& s1, const set& s2);
	// postcondition: returned whether s1 & s2 are equal
	//Efficiency: O(n)

	friend std::ostream& operator << (std::ostream& output, const set& s);
	// postcondition: s has been displayed on output
	//Efficiency: O(n)

private:
	node* head;
	size_type used;

};


#endif
