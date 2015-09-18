// Authors: Ngoc Bui and Kim Nguyen
#ifndef linkedlistH
#define linkedlistH

#include "day.h"

class LinkedList;

class ListNode
{
	Day day;
	ListNode *next;
	ListNode ();
	ListNode (const Day &d, ListNode *n);
	friend class LinkedList;
}; // class ListNode

class LinkedList
{
	int count;
	ListNode *head;
	public:
		LinkedList();
		~LinkedList();
		const Day &operator [] (int index) const;
		Day &operator [] (int index);
		LinkedList &operator += (const Day &d);
		LinkedList &operator -= (const Day &d);
}; // class LinkedList

#endif
