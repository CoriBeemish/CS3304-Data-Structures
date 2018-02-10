// FILE: set.h
// CLASS IMPLEMENTED: set.h

#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
  typedef int value_type;
  typedef std::size_t size_type;
  static const size_type INITIAL_CAPACITY = 30;

  set(size_type initial_capacity = INITIAL_CAPACITY);
  // postcondition: empty set has been created
  // Efficiency: O(1)

  ~set();
  // postcondition: set has been deallocated
  // Efficiency: O(1)

  set (const set& source);
  // postcondition: a copy of source has been created
  // Efficiency: O(1)

  set& operator = (const set& source);
  // postcondition:
  // Efficiency: O(1)

  void insert (const value_type& entry);
  // postcondition: entry is in the set
  // Efficiency: O(n)

  void remove (const value_type& entry);
  // postcondition: entry is not in the set
  // Efficiency: O(n)

  size_type size() const;
  // postcondition: number of elements in the set has been returned
  // Efficiency: O(1)

  bool contains (const value_type& entry) const;
  // postcondition: whether entry is in the set has been returned
  // Efficiency: O(1)

  friend set set_union (const set& s1, const set& s2);
  //postcondition: union of s1 & s2 has been returned
  // Efficiency: O(n)

  friend set set_intersection (const set& s1, const set& s2);
  // postcondition: intersection of s1 & s2 has been returned
  // Efficiency: O(n)

  friend set set_difference (const set& s1, const set& s2);
  // postcondition: difference of s1 - s2 has been returned
  // Efficiency: O(n)

  friend bool is_subset (const set& s1, const set& s2);
  // postcondition: returned whether s1 is a subset of s2
  // Efficiency: O(n)

  friend bool operator == (const set& s1, const set& s2);
  // postcondition: returned whether s1 & s2 are equal
  // Efficiency: O(n)

  friend std::ostream& operator << (std::ostream& output, const set& s);
  // postcondition: s has been displayed on output
  // Efficiency: O(n)

private:
  size_type find (const value_type& entry) const;
  // returned location of entry in the set if entry is in the set - used otherwise
  // Efficiency: O(n)
  void resize (unsigned int new_size);
  // Efficiency: O(1)
  value_type* data;
  size_type used;
  size_type capacity;
};


#endif
