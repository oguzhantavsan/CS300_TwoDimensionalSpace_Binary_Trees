#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "Rectangle.h"
#include <vector>
using namespace std;

struct node//bound elements which are in same tree
{
	Rectangle element;
	node *next;
	node *prev;	
};
struct rectangle_query
{
	int top;
	int left;
	int bottom;
	int right;
};
class LinkedList
{
public:
	LinkedList::LinkedList();//constructor
	int search(Rectangle rec, vector<rectangle_query> &query);//search rectangles in twodimtree
	void LinkedList::insert(Rectangle rec);//insert rectangle in twodintree
private:
	node *head;
	node *tail;
	int size;
};
#endif