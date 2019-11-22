#include "ListNode.h"
#include <iostream>

using namespace std;
ListNode::ListNode()
{
}

ListNode::ListNode(int val)
{
	prev = new ListNode;
	next = new ListNode;
	value = val;
}


ListNode::~ListNode()
{
}