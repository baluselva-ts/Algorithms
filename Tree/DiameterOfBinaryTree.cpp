//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
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

int getDiameter(NODE root, int *maxDiameter) {
	if (!root)
		return 0;
	int heightOfLeftSubtree = getDiameter(root -> left, maxDiameter);
	int heightOfRightSubtree = getDiameter(root -> right, maxDiameter);
	*maxDiameter = MAX(*maxDiameter, heightOfLeftSubtree + heightOfRightSubtree);
	return (1 + MAX(heightOfLeftSubtree, heightOfRightSubtree));
}

int main() {
	int *maxDiameter = (int *)malloc(sizeof(int));

	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	*maxDiameter = INT_MIN;
	getDiameter(root, maxDiameter);
	cout << "Maximum Diameter of Tree: " << *maxDiameter;
	cout << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	*maxDiameter = INT_MIN;
	getDiameter(root, maxDiameter);
	cout << "Maximum Diameter of Tree: " << *maxDiameter;
	cout << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	*maxDiameter = INT_MIN;
	getDiameter(root, maxDiameter);
	cout << "Maximum Diameter of Tree: " << *maxDiameter;
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
	*maxDiameter = INT_MIN;
	getDiameter(root, maxDiameter);
	cout << "Maximum Diameter of Tree: " << *maxDiameter;
	cout << endl;
	
	return 0;
}