//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
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

bool isBalanced(NODE root, int *height) {
	if (!root) {
		*height = 0;
		return 1;
	}
	int heightOfLeftSubTree = 0;
	int heightOfRightSubTree = 0;
	int isLeftBalanced = isBalanced(root -> left, &heightOfLeftSubTree);
	int isRightBalanced = isBalanced(root -> right, &heightOfRightSubTree);
	*height = MAX(heightOfLeftSubTree, heightOfRightSubTree) + 1;
	return (abs(heightOfLeftSubTree - heightOfRightSubTree) <= 1) && isLeftBalanced && isRightBalanced;

}

int main() {
	int height = 0;

	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	height = 0;
	if (isBalanced(root, &height))
		cout << "Tree is Balanced";
	else
		cout << "Tree is not Balanced";
	cout << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	height = 0;
	if (isBalanced(root, &height))
		cout << "Tree is Balanced";
	else
		cout << "Tree is not Balanced";
	cout << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	height = 0;
	if (isBalanced(root, &height))
		cout << "Tree is Balanced";
	else
		cout << "Tree is not Balanced";
	cout << endl;

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
	height = 0;
	if (isBalanced(root, &height))
		cout << "Tree is Balanced";
	else
		cout << "Tree is not Balanced";
	cout << endl;

	return 0;
}