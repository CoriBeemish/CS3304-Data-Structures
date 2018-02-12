// FILE: set.cpp
// AUTHOR: Cori Beemish

#include <cassert> // Provides assert
#include <cstdlib>  // Provides NULL, rand, size_t

#include "set.h"
#include "node1.h"

using namespace std;
using namespace main_savitch_5;

set::set()
{
	head = NULL;
	used = 0;
}

set::~set()
{
	if (head != NULL)
	{
		list_clear(head);
	}
	used = 0; 
}

set::set(const set& source)
{
	used = source.used;
	node *tail;  // Need for list_copy
	list_copy(source.head, head, tail);
}

set& set::operator = (const set& source)
{
	node *tail; 
	if (this == &source) 
	{
		return *this; 
	}
	list_clear(head);  
	used = 0;  
	list_copy(source.head, head, tail); 
	used = source.used; 
	return *this;
}

void set::insert(const value_type& entry)
{
	if (head == NULL)
	{
		list_head_insert(head, entry);
	}
	else
	{
		if (!contains(entry))
		{
			node *temp = head;
			list_insert(temp, entry);
			temp = temp->link();
		}
	}
	++used;
}

void set::remove(const value_type& entry)
{
	node *entry_ptr;
	entry_ptr = list_search(head, entry);

	if (entry_ptr == NULL)
	{
		return; 
	}
	while (entry_ptr != NULL) 
	{
		entry_ptr->set_data(head->data());
		entry_ptr = entry_ptr->link();
		entry_ptr = list_search(entry_ptr, entry);
		list_head_remove(head);
	}
	--used;
}

set::size_type set::size() const
{
	return used;
}

bool set::contains(const value_type& entry) const
{
	const node *containsTemp = list_search(head, entry);

	while (containsTemp != NULL)
	{
		containsTemp = containsTemp->link();
		containsTemp = list_search(containsTemp, entry);
		return true;
	}
	return false;
}

set set_union(const set& s1, const set& s2)
{
	node *s1Union = s1.head;
	node *s2Union = s2.head;
	set unionSet;

	if (s1Union == NULL)
	{
		unionSet.insert(s2Union->data());
		return unionSet;
	}
	if (s2Union == NULL)
	{
		unionSet.insert(s1Union->data());
		return unionSet;
	}
	while (s1Union != NULL)
	{
		unionSet.insert(s1Union->data());
		s1Union = s1Union->link();
	}
	while (s2Union != NULL)
	{
		if (!s1.contains(s2Union->data()))
		{
			unionSet.insert(s2Union->data());
		}
		s2Union = s2Union->link();
	}
	return unionSet;
}

set set_intersection(const set& s1, const set& s2)
{
	node *s1Inter = s1.head;
	node *s2Inter = s2.head;
	set interSet;

	while (s1Inter != NULL)
	{
		if (s2.contains(s1Inter->data()))
		{
			interSet.insert(s1Inter->data());
		}
		s1Inter = s1Inter->link();
	}
	return interSet;
}

set set_difference(const set& s1, const set& s2)
{
	node *s1Diff = s1.head;
	node *s2Diff = s2.head;
	set diffSet;

	while (s1Diff != NULL)
	{
		if (!s2.contains(s1Diff->data()))
		{
			diffSet.insert(s1Diff->data());
		}
		s1Diff = s1Diff->link();
	}
	return diffSet;
}

bool is_subset(const set& s1, const set& s2)
{
	node *s1Subset = s1.head;
	node *s2Subset = s2.head;
	set diffSet;

	while (s1Subset != NULL)
	{
		if (!s2.contains(s1Subset->data()))
		{
			return false;
		}
		s1Subset = s1Subset->link();
	}
	return true;
}

bool operator == (const set& s1, const set& s2)
{
	node *s1Operator = s1.head;
	node *s2Operator = s2.head;

	while (s1Operator &&  s2Operator)
	{
		if (s1Operator->data() != s2Operator->data())
		{
			return false;
		}
		s1Operator = s1Operator->link();
		s2Operator = s2Operator->link();
	}

	if (s1Operator == NULL && s2Operator == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator << (std::ostream& output, const set& s)
{
	node* temp = s.head;
	if (temp == NULL)
	{
		output << "Empty set";
	}
	else
	{
		while (temp != NULL)
		{
			output << temp->data() << " ";
			temp = temp->link();
		}
	}
	return output;
}
