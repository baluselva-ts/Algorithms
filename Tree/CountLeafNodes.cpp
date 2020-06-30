#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long
#define NODE struct node*

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createNode(int value) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> data = value;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

int countLeafNodes(NODE root) {
	if (!root)
		return 0;
	if (!root -> left && !root -> right)
		return 1;
	return countLeafNodes(root -> left) + countLeafNodes(root -> right);
	
}

int main() {

	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	cout << "Tree has ";
	cout << countLeafNodes(root);
	cout << " leaf nodes" << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	cout << "Tree has ";
	cout << countLeafNodes(root);
	cout << " leaf nodes" << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	cout << "Tree has ";
	cout << countLeafNodes(root);
	cout << " leaf nodes" << endl;

	root = createNode(1);
	root -> left = createNode(2);
	root -> left -> left = createNode(3);
	root -> right = createNode(4);
	root -> right -> right = createNode(8);
	root -> right -> left = createNode(5);
	root -> right -> left -> right = createNode(6);
	root -> right -> left -> right -> right = createNode(7);
	root -> right -> left -> right -> right -> left = createNode(12);
	root -> right -> left -> right -> right -> left -> right = createNode(13);
	root -> right -> left -> right -> right -> left -> right -> left = createNode(14);
	root -> right -> right -> right = createNode(9);
	root -> right -> right -> right -> left = createNode(10);
	root -> right -> right -> right -> left -> right = createNode(11);
	cout << "Tree has ";
	cout << countLeafNodes(root);
	cout << " leaf nodes" << endl;

	return 0;
}