//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
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

int printLeastCommonAncestor(NODE root, int firstNumber, int secondNumber, NODE *lca) {
	if (!root)
		return 0;
	int value = printLeastCommonAncestor(root -> left, firstNumber, secondNumber, lca) + printLeastCommonAncestor(root -> right, firstNumber, secondNumber, lca);
	if (root -> data == firstNumber || root -> data == secondNumber)
		value++;
 	if (value == 2) {
 		value ++;
 		*lca = root;
 	}
 	return value;
}

int main() {

	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	NODE lca = NULL;
	printLeastCommonAncestor(root, 5, 6, &lca);
	(lca) ? cout << "Common Ancestor: " << lca -> data : cout << "No common Ancestor";
	cout << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	lca = NULL;
	printLeastCommonAncestor(root, 5, 6, &lca);
	(lca) ? cout << "Common Ancestor: " << lca -> data : cout << "No common Ancestor";
	cout << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	lca = NULL;
	printLeastCommonAncestor(root, 6, 7, &lca);
	(lca) ? cout << "Common Ancestor: " << lca -> data : cout << "No common Ancestor";
	cout << endl;

	return 0;
}