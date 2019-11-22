#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode();
	ListNode(int val);
	~ListNode();

	inline void setPrev(ListNode &node) { *prev = node; }
	inline ListNode *getPrev() { return prev; }
	inline void setNext(ListNode &node) { *next = node; }
	inline ListNode *getNext() { return next; }
	inline void setValue(int val) { value = val; }
	inline int getValue() { return value; }

private:
	ListNode *prev;
	ListNode *next;
	int value;
};
