#include "LinkedList.h"
#include <iostream>
#include <vector>


using namespace std;
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}
void LinkedList::insert(Rectangle rec)//insert rectangle in twodintree
{
	if (head == NULL&&tail==NULL)
	{
		node *temp;
		temp = new node;
		temp->element = rec;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
	else
	{
		node *temp = new node;
		temp->element = rec;
		temp->next = NULL;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	size++;
}

int LinkedList::search(Rectangle rec,vector<rectangle_query> &query)//search rectangles in twodimtree
{
	node *x = head;
	int count = 0;
	bool cond;
	if (x == NULL)//if tree is empty
		return count;
	if (rec.getTop() >= x->element.getTop() && rec.getTop() < x->element.getBottom() && rec.getLeft() >= x->element.getLeft() && rec.getLeft() < x->element.getRight())
		cond = true;
	else
		cond = (x->element.getBottom() > rec.getBottom()&&x->element.getTop() <= rec.getTop()&&x->element.getLeft() <= rec.getLeft()&&x->element.getRight() > rec.getRight());//if the rectangle includes query or not
	while (x!=NULL)
	{
		if (rec.getTop() >= x->element.getTop() && rec.getTop() < x->element.getBottom() && rec.getLeft() >= x->element.getLeft() && rec.getLeft() < x->element.getRight())
			cond = true;
		else
			cond = (x->element.getBottom() > rec.getBottom() && x->element.getTop() <= rec.getTop() && x->element.getLeft() <= rec.getLeft() && x->element.getRight() > rec.getRight());//if the rectangle includes query or not
		rectangle_query qrec;
		if (cond==true)
		{
			qrec.top = x->element.getTop();
			qrec.left = x->element.getLeft();
			qrec.bottom = x->element.getBottom();
			qrec.right = x->element.getRight();
			query.push_back(qrec);
			count++;
		}
		x = x->next;
	}
	return count;
}
