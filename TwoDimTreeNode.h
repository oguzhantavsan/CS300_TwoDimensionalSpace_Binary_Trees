#ifndef TwoDimTreeNode_H_
#define TwoDimTreeNode_H_

#include <iostream>
#include "Rectangle.h"
#include "LinkedList.h"
#include <vector>

using namespace std;
class TwoDimTreeNode
{
public:
	TwoDimTreeNode::TwoDimTreeNode();//constructor
	TwoDimTreeNode::TwoDimTreeNode(Rectangle rec);//equalize extent of rectangle with given rectangle
	void TwoDimTreeNode::add(TwoDimTreeNode *tree, Rectangle rec);//add rectangle in given tree
	int TwoDimTreeNode::searhforquery(TwoDimTreeNode *tree, int x, int y, vector<rectangle_query> &p,int &count);//search query coordinates in given tree and add them in given vector
	TwoDimTreeNode::~TwoDimTreeNode();
private:
	Rectangle Extent;//extent of tree
	LinkedList Vertical, Horizontal;//vertical and horizontal nodes
	node *next, *prev;
	TwoDimTreeNode *TopLeft, *TopRight, *BottomLeft, *BottomRight;//children of tree
};
#endif