#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
	AVLTree<int> tree;

	tree.insert(5);
	tree.insert(21);
	tree.insert(17);
	tree.insert(10);
	tree.insert(7);
	tree.insert(12);
	tree.insert(400);
	tree.insert(22);
	tree.insert(36);
	tree.insert(50);

	tree.display();
	cout << "Tree height: " << tree.treeHeight() << endl;

	AVLTree<int> tree2;
	int size = 100000;
	for (int i = 0; i < size; i++)
	{
		tree2.insert(rand());
	}
	cout << "Tree height: " << tree2.treeHeight() << endl;

	AVLTree<int> tree3;
	for (int i = 0; i < size; i++)
	{
		tree3.insert(i);
	}
	cout << "Tree height: " << tree3.treeHeight() << endl;

	////now implement a sorting routine using your AVLTree.
	////What is the worst case big-Oh run time of your sort? 
	int size2 = 25;
	int * numbers = new int[size2];
	for (int i = 0; i < size2; i++)
		numbers[i] = rand();

	AVLTree<int> tree4;
	tree4.sort(numbers, 0, size2 - 1);

	for (int i = 0; i < size2; i++)
		cout << numbers[i] << endl;

	cout << endl;

	tree4.display();

	return 0;
}