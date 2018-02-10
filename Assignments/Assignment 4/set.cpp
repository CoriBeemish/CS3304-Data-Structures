// FILE: set.cpp
// AUTHOR: Cori Beemish
// DATE: 06/22/2017

#include "set.h"
#include <cassert>
using namespace std;

const set::size_type set::INITIAL_CAPACITY;

set::set(size_type initial_capacity)
{
    data = new value_type [initial_capacity];
    capacity = initial_capacity;
    used = 0;
}

set::set (const set& source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    copy(source.data, source.data + used, data);
}

set::~set()
{
    delete [ ] data;
    used = 0;
}

set& set::operator = (const set& source)
{
    if (this == &source)
    {
        return *this;
    }
	if (capacity != source.capacity)
	{
	    value_type *new_data = new value_type[source.capacity];
	    delete [ ] data;
	    data = new_data;
	    capacity = source.capacity;
	}
	used = source.used;
	copy(source.data, source.data + used, data);
}

void set::insert (const value_type& entry)
{
    if (!contains(entry))
    {
        if (size() == capacity)
        {
            resize (2 * capacity);
        }
        data[used] = entry;
        ++used;
    }
}

void set::remove (const value_type& entry)
{
    if (contains(entry))
    {
        data [entry] = data [used - 1];
        --used;
    }
}

set::size_type set::size() const
{
    return used;
}

bool set::contains (const value_type& entry) const
{
    for (size_type i = 0; i < size(); i++)
    {
        if (entry == data[i])
        {
            return true;
        }
    }
    return false;
}

set set_union (const set& s1, const set& s2)
{
    set unionSet;
    for(size_t i = 0; i < s1.size(); i++)
    {
        unionSet.insert(s1.data[i]);
    }
    for(size_t j = 0; j < s2.size(); j++)
    {
        unionSet.insert(s2.data[j]);
    }
    return unionSet;
}

set set_intersection (const set& s1, const set& s2)
{
    set intersection;
    for(size_t i = 0; i < s1.size(); i++)
    {
        if(s2.contains(s1.data[i]))
        {
            intersection.insert(s1.data[i]);
        }
    }
    return intersection;
}

set set_difference (const set& s1, const set& s2)
{
    set setDifference;
    for(size_t i = 0; i < s1.size(); i++)
    {
        if(!s2.contains(s1.data[i]))
        {
            setDifference.insert(s1.data[i]);
        }
    }
    return setDifference;
}

bool is_subset (const set& s1, const set& s2)
{
    for(size_t i = 0; i < s2.size( ); i++)
    {
        for(size_t j = 0; j < s1.size( ); j++)
        {
            if (!s2.contains(s1.data[j]) )
            {
                return false;
            }
        }
    }
    return true;
}

bool operator == (const set& s1, const set& s2)
{
    for(size_t i = 0; i < s2.size( ); i++)
    {
        for(size_t j = 0; j < s1.size( ); j++)
        {
            if (s2.data[i] == s1.data[j])
            {
                return true;
            }
        }
    }
    return false;
}

std::ostream& operator << (std::ostream& output, const set& s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        output << (s.data[i]) << " ";
    }
    return output;
}

void set::resize (unsigned int new_size)
{
     assert(new_size > 0);
    if (new_size == capacity)
    {
        return;
    }
    if (new_size < used)
    {
        new_size = used;
    }
    value_type *larger_array = new value_type[new_size];
    copy(data, data + used, larger_array);
    delete [ ] data;
    data = larger_array;
    capacity = new_size;
}
