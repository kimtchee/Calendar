// Authors: Ngoc Bui and Kim Nguyen
#include <iostream>
#include <iomanip>
#include "linkedlist.h"
#include "day.h"

using namespace std;

ListNode::ListNode()
{
	next = NULL;
} // ListNode()

ListNode::ListNode(const Day &d, ListNode *n): day(d), next(n)
{
} // copy constructor

LinkedList::LinkedList(): count(0)
{
  head = new ListNode;
} // LinkedList()

LinkedList::~LinkedList()
{
	ListNode *nodePtr, *nextNode;
	nodePtr = head;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
} // ~LinkedList()

const Day & LinkedList::operator[] (int index) const 
{
	ListNode *nodePtr;
	nodePtr = head;
	for(int i = 0; i < index; i++)
	{
		nodePtr = nodePtr->next;
	}
	return nodePtr->day;
} // operator[] **const**

Day & LinkedList::operator[] (int index)
{
	ListNode *nodePtr;
	nodePtr = head;
	for(int i = 0; i < index; i++)
	{
		nodePtr = nodePtr->next;
	}
	return nodePtr->day;
} // operator [] **non-const**

LinkedList& LinkedList::operator+= (const Day &d){
	ListNode *newNode, *nodePtr, *previousNode;
	newNode = new ListNode;
	newNode->day = d;
	if (!head){
		head = newNode;
		newNode->next = NULL;
		count = 1;
	}
	else{
		nodePtr = head;
		while (nodePtr != NULL && nodePtr->day < d){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == NULL){
			head = newNode;
			newNode = nodePtr;
		}
		else{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
		count++;
	}
	return *this;
} // operator +=

LinkedList& LinkedList::operator-= (const Day &d){
	ListNode *nodePtr, *previousNode;
	if (!head)
		return *this;
	if (head->day == d)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		count = 0;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL && nodePtr->day != d)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNode->next = nodePtr->next;
		delete nodePtr;
		count--;
	}
	return *this;
} // operator-=




