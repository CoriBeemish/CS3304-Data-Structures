// FILE: set.cpp
// AUTHOR: Cori Beemish
// DATE: 06/13/2017
// CLASS IMPLEMENTED: set (See set.h for documentation.)

#include "set.h"
#include <cassert> //Provides assert

using namespace std;

set::set()
{
    used = 0;
}

set::size_type set::size() const
{
    return used;
}

void set::insert (const value_type& entry)
{
    if (contains(entry) == true)
    {
        return;
    }
    data[used] = entry;
    used++;
}

void set::remove (const value_type& entry)
{
    if (contains(entry))
    {
        data [entry] = used;
        --used;
    }
}

set::size_type set::find (const value_type& entry) const
{
    size_type location = 0;
    while (location < size() && data[location] != entry)
    {
        location++;
    }
    return location;
}

bool set::contains (const value_type& entry) const
{
    return find (entry) < used;
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
        if(s1.contains(s2.data[i]))
        {
            intersection.insert(s2.data[i]);
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
