#include "TwoDimTreeNode.h"

TwoDimTreeNode::TwoDimTreeNode()
{
	TopLeft = NULL;
	TopRight = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
}
TwoDimTreeNode::TwoDimTreeNode(Rectangle rec)//equalize extent of rectangle with given rectangle
{
	TopLeft = NULL;
	TopRight = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
	Extent = rec;
}

void TwoDimTreeNode::add(TwoDimTreeNode *tree, Rectangle rec)
{
	int horizontal = (tree->Extent.getBottom() + tree->Extent.getTop()) / 2;//horizontal axis of extent
	int vertical = (tree->Extent.getLeft() + tree->Extent.getRight()) / 2;//vertical axis of extent
	bool con2 = vertical<=rec.getRight() && vertical>=rec.getLeft();//if rectangle is on vertical axis or not
	bool con3 = horizontal>=rec.getTop() && horizontal<=rec.getBottom();//if rectangle is on horizontal axis or not

	if (horizontal != 1 && vertical != 1)//continue until width of tree is 1
	{
		if (con2 == true)//if rectangle is on vertical axis or not
		{
			tree->Vertical.insert(rec);
		}
		else if (con2 != true && con3 == true)//if rectangle is on horizontal axis or not
		{
			tree->Horizontal.insert(rec);
		}
		else if (!rec.check_top(rec.getBottom(), horizontal) && rec.check_left(rec.getRight(), vertical))//if rec is at topleft or not
		{
			//set extent of tree
			Rectangle x(tree->Extent.getTop(), (tree->Extent.getBottom() + tree->Extent.getTop()) / 2, tree->Extent.getLeft(), (tree->Extent.getLeft() + tree->Extent.getRight()) / 2);

			if (tree->TopLeft == NULL)
			{
				tree->TopLeft = new TwoDimTreeNode(x);
			}
			tree->TopLeft->add(tree->TopLeft, rec);
		}
		else if (!rec.check_top(rec.getBottom(), horizontal) && !rec.check_left(rec.getLeft(), vertical))//if rec is at topright or not
		{
			//set extent of tree
			Rectangle x(tree->Extent.getTop(), (tree->Extent.getBottom() + tree->Extent.getTop()) / 2, (tree->Extent.getLeft() + tree->Extent.getRight()) / 2, tree->Extent.getRight());
			if (tree->TopRight == NULL)
			{
				tree->TopRight = new TwoDimTreeNode(x);
			}
			tree->TopRight->add(tree->TopRight, rec);
		}
		else if (rec.check_top(rec.getTop(), horizontal) && rec.check_left(rec.getRight(), vertical))//if rec is at bottomleft or not
		{
			//set extent of tree
			Rectangle x((tree->Extent.getBottom() + tree->Extent.getTop()) / 2, tree->Extent.getBottom(), tree->Extent.getLeft(), (tree->Extent.getLeft() + tree->Extent.getRight()) / 2);
			if (tree->BottomLeft == NULL)
			{
				tree->BottomLeft = new TwoDimTreeNode(x);
			}
			tree->BottomLeft->add(tree->BottomLeft, rec);
		}
		else if (rec.check_top(rec.getTop(), horizontal) && !rec.check_left(rec.getLeft(), vertical))//if rec is at bottomright or not
		{
			//set extent of tree
			Rectangle x((tree->Extent.getBottom() + tree->Extent.getTop()) / 2, tree->Extent.getBottom(), (tree->Extent.getLeft() + tree->Extent.getRight()) / 2, tree->Extent.getRight());
			if (tree->BottomRight == NULL)
			{
				tree->BottomRight = new TwoDimTreeNode(x);
			}
			tree->BottomRight->add(tree->BottomRight, rec);
		}
	}
	else if (vertical == 1 || horizontal == 1)
		tree->Horizontal.insert(rec);
}

int TwoDimTreeNode::searhforquery(TwoDimTreeNode *tree, int x, int y, vector<rectangle_query> &p, int &count)//search query coordinates in given tree and add them in given vector
{
	int horizontal = (tree->Extent.getBottom() + tree->Extent.getTop()) / 2;//horizontal axis of extent
	int vertical = (tree->Extent.getLeft() + tree->Extent.getRight()) / 2;//vertical axis of extent
	Rectangle r(y , y+1, x , x+1);
	if (x == vertical)//if x coordinate on vertical axis or not
	{
		count += tree->Vertical.search(r, p);
	}
	else if (x != vertical&&y == horizontal)//if y coordinate on horizontal axis or not
	{
		count += tree->Horizontal.search(r, p);
	}
	else if (x < vertical&&y < horizontal)//if query is at topleft or not
	{
		count += tree->Vertical.search(r, p);
		count += tree->Horizontal.search(r, p);
		if(tree->TopLeft!=NULL)
		tree->TopLeft->searhforquery(tree->TopLeft, x, y, p, count);
	}
	else if (x > vertical&&y < horizontal)//if query is at topright or not
	{
		count += tree->Vertical.search(r, p);
		count += tree->Horizontal.search(r, p);
		if (tree->TopRight != NULL)
		tree->TopRight->searhforquery(tree->TopRight, x, y, p, count);
	}
	else if (x < vertical&&y > horizontal)//if query is at bottomleft or not
	{
		count += tree->Vertical.search(r, p);
		count += tree->Horizontal.search(r, p);
		if (tree->BottomLeft != NULL)
		tree->BottomLeft->searhforquery(tree->BottomLeft, x, y, p, count);
	}
	else if (x > vertical&&y > horizontal)//if query is at bottomright or not
	{
		count += tree->Vertical.search(r, p);
		count += tree->Horizontal.search(r, p);
		if (tree->BottomRight != NULL)
		tree->BottomRight->searhforquery(tree->BottomRight, x, y, p, count);
	}
	return count;
}

TwoDimTreeNode::~TwoDimTreeNode()
{
}




