#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template<class THING>
class AVLTree
{
private:
	class node
	{
	public:
		THING data;
		node * left;
		node * right;

		//height of node in tree
		int height;

		node(THING x)
		{
			data = x;
			left = NULL;
			right = NULL;
			height = 0;
		}
	};

	int getHeight(node * r)
	{
		if (r == NULL)
			return -1;
		else
			return r->height;
	}

	node * root;

	//update r's height to correct
	//value
	void updateHeight(node * r)
	{
		r->height = 1 + max(getHeight(r->left), getHeight(r->right));
	}


	void insert(node * &r, THING x)
	{
		if (r == NULL)
		{
			r = new node(x);
		}
		else
		{
			if (x < r->data)
			{
				insert(r->left, x);
			}
			else
			{
				insert(r->right, x);
			}

			//r's height may have changed
			//after inserting
			updateHeight(r);
		}

		balance(r);
	}

	void balance(node * &r)
	{
		if (getHeight(r->left) - getHeight(r->right) > 1)
		{
			if (getHeight(r->left->left) >= getHeight(r->left->right))
			{
				singleRightRotation(r);
			}
			else
				doubleLeftRightRotation(r);
		}
		else
		{
			if (getHeight(r->right) - getHeight(r->left) > 1)
			{
				if (getHeight(r->right->right) >= getHeight(r->right->left))
				{
					singleLeftRotation(r);
				}
				else
					doubleRightLeftRotation(r);
			}
		}

		updateHeight(r);
	}

	//print all items in tree
	//rooted at r
	void display(node * r)
	{
		if (r == NULL)
		{
			//do nothing
		}
		else
		{
			display(r->left);
			cout << r->data << endl;
			display(r->right);
		}
	}

	//delete tree rooted at r
	void deleteTree(node * r)
	{
		if (r != NULL)
		{
			deleteTree(r->left);
			deleteTree(r->right);
			delete r;
		}
	}

	void singleLeftRotation(node * &r)
	{
		node * a = r;
		node * b = a->right;
		node * bLeft = b->left;

		r = b;
		b->left = a;
		a->right = bLeft;

		//Update height of the depper trees first
		updateHeight(a);
		updateHeight(b);
	}

	void singleRightRotation(node * &r)
	{
		node * a = r;
		node * b = a->left;
		node * bRight = b->right;

		r = b;
		b->right = a;
		a->left = bRight;

		//Update height of the depper trees first
		updateHeight(a);
		updateHeight(b);
	}

	void doubleRightLeftRotation(node * &r)
	{
		node * a = r;
		node * b = a->right;
		node * c = b->left;
		node * cLeft = c->left;
		node * cRight = c->right;

		r = c;
		c->left = a;
		c->right = b;
		a->right = cLeft;
		b->left = cRight;

		//Update height of the depper trees first
		updateHeight(a);
		updateHeight(b);
		updateHeight(c);

	}

	void doubleLeftRightRotation(node * &r)
	{
		node * a = r;
		node * b = a->left;
		node * c = b->right;
		node * cLeft = c->left;
		node * cRight = c->right;

		r = c;
		c->left = b;
		c->right = a;
		b->right = cLeft;
		a->left = cRight;

		//Update height of the depper trees first
		updateHeight(a);
		updateHeight(b);
		updateHeight(c);
	}

	void sort(THING A[], int start, int end,node * &r)
	{
		if (start == end)
		{
		}
		else
		{
			insert(r, A[start]);
			sort(A, start + 1, end);
		}

	}

public:

	//don't leave your nodes lying around,
	//pick up after yourself,
	//this isn't java.
	~AVLTree()
	{
		deleteTree(root);
	}

	AVLTree()
	{
		root = NULL;
	}

	void insert(THING x)
	{
		insert(root, x);
	}

	void display()
	{
		display(root);
	}

	int treeHeight()
	{
		return getHeight(root);
	}

	void sort(THING A[], int start, int end)
	{
		sort(A, start, end, root);
	}

};