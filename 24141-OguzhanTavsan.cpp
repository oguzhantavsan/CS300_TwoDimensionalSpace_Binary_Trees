#include <iostream>
#include <fstream>  
#include <sstream> 
#include <iomanip> 
#include <cctype>        
#include <string>
#include <vector>
#include "Rectangle.h"
#include "TwoDimTreeNode.h"
#include "LinkedList.h"

using namespace std;
int main()
{
	string filename = "rectdb.txt";
	ifstream in;
	in.open(filename.c_str());
	string line;
	bool checkforquery = false;//Check for passing for query coordinates
	int top=0,left=0,bottom=0,right=0;
	int x=0, y=0;
	int count = 0;
	Rectangle rec2;
	getline(in, line);
	istringstream str(line);
	str >> top >> left >> bottom >> right;
	Rectangle extent(top,bottom,left,right);
	TwoDimTreeNode *tree = new TwoDimTreeNode(extent);
	while (getline(in, line)&&x!=-1)
	{
		istringstream str(line);
		if (checkforquery != true)
		{
			str >> top;
			if (top < 0)//Check for passing for query coordinates
			{
				checkforquery = true;
			}
			if (checkforquery == false)
			{
				str >> left >> bottom >> right;
				Rectangle rec(top, bottom, left, right);
				tree->add(tree, rec);
			}
		}
		if (checkforquery == true)
		{
			
			if (top >= 0)
			{
				str >> x;
				if (x >= 0)
				{
					str >> y;
					vector<rectangle_query> rp;//store rectangles which includes x,y coordinates
					int count1 = 0;
					int count = 0;
					rectangle_query qrec;
					TwoDimTreeNode *temp = tree;
					count1 = temp->searhforquery(temp, x, y, rp, count);
					cout << x << " " << y << endl;
					cout << count1 << endl;
					while (!rp.empty())
					{
						qrec = rp.back();
						cout << qrec.top << " " << qrec.left << " " << qrec.bottom << " " << qrec.right << endl;
						rp.pop_back();
					}
				}
			}
			top = 0;
		}
	}
	return 0;
}