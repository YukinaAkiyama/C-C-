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
		althought it is easy, I am unwilling to write.
	}
*/

void release(Node* tree) {
	if (tree != 0) {
		release(tree->left);
		release(tree->right);
		delete tree;
	}
}

/*题目要求的算法: 本质是一个中序遍历*/
void showAllGreatEqualX(Node* biSortTree, int x) {
	if (biSortTree != 0) {
		showAllGreatEqualX(biSortTree->left, x);
		if (biSortTree->data >= x)
			cout << biSortTree->data << " ";
		showAllGreatEqualX(biSortTree->right, x);
	}
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
	showAllGreatEqualX(biSortTree, 35);
	release(biSortTree);
	return 0;
}
