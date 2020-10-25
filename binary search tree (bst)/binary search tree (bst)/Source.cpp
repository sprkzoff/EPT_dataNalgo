
//Open with VS2012 -> graphic example (openframework)

#include "ofApp.h"
#include<stdio.h>

class treenode
{
public:
	int data;
	treenode();
	void draw(int x, int y);
	treenode *l;
	treenode *r;

};




class treenodeString : public treenode
{
public:
	int data;
	treenodeString();

	treenodeString *l;
	treenodeString *r;
};

treenode::treenode()
{
	l = NULL;
	r = NULL;
}

void treenode::draw(int x, int y)
{
	char text[50];
	sprintf(text, "%d", data);

	ofSetColor(255, 130, 0);
	ofFill();
	ofCircle(x, y, 10);
	ofSetHexColor(0x000000);
	ofDrawBitmapString(text, x, y);

}

class bst
{
public:
	treenode *root;
	bst();
	int ppx, ppy;
	int draw(treenode *n, int x, int y);
	int findheight();
	int findheight2(treenode *n);
	void add(int x);
	void paint(int w, int h);
	void preorder(treenode *n);
	int numnode();
	int numnode2(treenode *n);
	bool find(int x);
};

bst::bst()
{
	root = NULL;
}

int bst::numnode()
{
	return numnode2(root);
}

int bst::draw(treenode *n, int x, int y)
{
	int xr = x;
	if (n == NULL)
	{
		return xr;
	}
	int lx = draw(n->l, x, y + 1);

	xr += numnode2(n->l);
	int rx = draw(n->r, xr + 1, y + 1);

	n->draw(xr*ppx, y*ppy);
	if (n->l != NULL)
	{
		ofLine(xr*ppx, y*ppy, (lx)*ppx, (y + 1)*ppy);
	}
	if (n->r != NULL)
	{
		ofLine(xr*ppx, y*ppy, (rx)*ppx, (y + 1)*ppy);
	}
	return (xr);
}

int bst::numnode2(treenode *n)
{
	if (n == NULL)
	{
		return 0;
	}
	if (n->l == NULL && n->r == NULL)
	{
		return 1;
	}
	int ln = 0, rn = 0, m, rh = 0, lh = 0;
	if (n->l != NULL)
	{
		ln = numnode2(n->l);
	}
	if (n->r != NULL)
	{
		rn = numnode2(n->r);
	}
	m = ln + rn + 1;
	return m;
}

void bst::preorder(treenode *n)
{
	if (n == NULL)
	{
		return;
	}
	printf("%d ", n->data);
	preorder(n->l);
	preorder(n->r);
}

void bst::paint(int w, int h)
{

	ppx = (int)(w / (2 + numnode()));
	ppy = (int)(h / (2 + findheight()));
	draw(root, 1, 1);
}

int bst::findheight()
{
	return findheight2(root);
}

int bst::findheight2(treenode *n)
{
	if (n == NULL)
	{
		return -1;
	}
	if (n->l == NULL && n->r == NULL)
	{
		return 0;
	}
	int lh = 0, rh = 0, m;
	if (n->l != NULL)
	{
		lh = findheight2(n->l);
	}
	if (n->r != NULL)
	{
		rh = findheight2(n->r);
	}
	if (lh > rh)
	{
		m = lh + 1;
	}
	else
	{
		m = rh + 1;
	}
	return m;
}

void bst::add(int x)
{
	if (root == NULL)
	{
		root = new treenode();
		root->data = x;
		return;
	}
	treenode *now = root;
	while (true)
	{
		if (now->data > x)
		{
			if (now->l == NULL)
			{
				now->l = new treenode();
				now->l->data = x;
				return;
			}
			else
			{
				now = now->l;
			}
		}
		else if (now->data < x)
		{
			if (now->r == NULL)
			{
				now->r = new treenode();
				now->r->data = x;
				return;
			}
			else
			{
				now = now->r;
			}
		}
		else
		{
			return;
		}
	}
}

bool bst::find(int x)
{
	if (root == NULL)
	{
		return false;
	}
	treenode *now = root;
	while (true)
	{
		if (now->data > x)
		{
			if (now->l == NULL)
			{
				return false;
			}
			else
			{
				now = now->l;
			}
		}
		else if (now->data < x)
		{
			if (now->r == NULL)
			{
				return false;
			}
			else
			{
				now = now->r;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}


void main()
{
	int x;
	bst tree;
	for (int i = 0; i< 200; i++)
	{
		tree.add(ofRandom(300));
	}
	x = tree.findheight();
	tree.paint(ofGetWidth(), ofGetHeight());
	printf("%d\n",x);
}

