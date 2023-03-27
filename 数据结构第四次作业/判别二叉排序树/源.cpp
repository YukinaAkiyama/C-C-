#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data = 0, Node* left = 0, Node* right = 0) :
		data(data),
		left(left),
		right(right)
	{

	}
};

void insert(Node*& biSortTree, int num) {
	if (biSortTree == 0) {
		biSortTree = new Node(num);
	}
	else if (num < biSortTree->data) {
		insert(biSortTree->left, num);
	}
	else {
		insert(biSortTree->right, num);
	}
}

Node* find(Node* biSortTree, int num) {
	if (biSortTree != 0) {
		if (biSortTree->data == num) {
			return biSortTree;
		}
		else if (num < biSortTree->data) {
			return find(biSortTree->left, num);
		}
		else {
			return find(biSortTree->right, num);
		}
	}
	return 0;
}

/*
	void delete(Node* biSortTree, int num){
		....
	}
*/

void release(Node* tree) {
	if (tree != 0) {
		release(tree->left);
		release(tree->right);
		delete tree;
	}
}

/*题目要求的算法，本质是二叉排序树的遍历*/
bool isBiSortTree(Node* tree) {
	if (tree != 0) {
		return isBiSortTree(tree->left) && isBiSortTree(tree->right) &&
			(tree->left != 0 ? tree->left->data < tree->data : true) &&
			(tree->right != 0 ? tree->right->data >= tree->data : true);
	}
	return true;
}


int main() {
	Node* biSortTree = 0;
	insert(biSortTree, 18);
	insert(biSortTree, 89);
	insert(biSortTree, 42);
	insert(biSortTree, 28);
	insert(biSortTree, 13);
	insert(biSortTree, 96);
	insert(biSortTree, 35);
	insert(biSortTree, 25);
	insert(biSortTree, 7);
	insert(biSortTree, 85);
	cout << find(biSortTree, 25)->data << endl;
	cout << find(biSortTree, 42)->data << endl;
	cout << find(biSortTree, 6) << endl;
	cout << "isBST: " << isBiSortTree(biSortTree) << endl;

	Node* plainTree = new Node(0, new Node(1, new Node(3), new Node(4)), new Node(2));
	cout << "isBST: " << isBiSortTree(plainTree) << endl;

	release(biSortTree);
	release(plainTree);
	return 0;
}
