#include <iostream>
#include"binarySearchTree.h"
#include"binaryTree.h"
using namespace std;



int main() {
	bSearchTreeType<int> Tree;

	Tree.insert(4);
	Tree.insert(23);
	Tree.insert(38);
	Tree.insert(64);
	Tree.insert(80);
	Tree.insert(123);
	Tree.insert(57);

	Tree.preorderTraversal();

	cout << "Tree has a " << Tree.treeLeavesCount() << " number of leaves." << endl;		

	cout << "Tree has a " << Tree.treeSingleParent() << " number of single parents." << endl;

	cout << "Largest element is: " << Tree.treeLargest() << endl;

	cout << "Swapped tree is " << endl;

	Tree.treeSwapSubtrees();
	Tree.preorderTraversal();

	return 0;
}