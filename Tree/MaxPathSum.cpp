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

int getMaxPathSum(NODE root, int *maxPathSum) {
	if(!root)
		return 0;
	int leftSubtree = getMaxPathSum(root -> left, maxPathSum);
	int rightSubtree = getMaxPathSum(root -> right, maxPathSum);
	*maxPathSum = MAX(*maxPathSum, leftSubtree + rightSubtree + root -> data);
	// cout << "\nRoot: " << root -> data << endl;
	// cout << "Left Sum: " << leftSubtree << endl;
	// cout << "Right Sum: " << rightSubtree << endl;
	// cout << "PathSum: " << pathSum << endl;
	// cout << "MaxPathSum: " << *maxPathSum << endl; 
	return (root -> data) + MAX(leftSubtree, rightSubtree);
}

int main() {
	int *maxPathValue = (int *)malloc(sizeof(int));

	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	*maxPathValue = INT_MIN;
	getMaxPathSum(root, maxPathValue);
	cout << "Max Path Sum: " << *maxPathValue;
	cout << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	*maxPathValue = INT_MIN;
	getMaxPathSum(root, maxPathValue);
	cout << "Max Path Sum: " << *maxPathValue;
	cout << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	*maxPathValue = INT_MIN;
	getMaxPathSum(root, maxPathValue);
	cout << "Max Path Sum: " << *maxPathValue;
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
	*maxPathValue = INT_MIN;
	getMaxPathSum(root, maxPathValue);
	cout << "Max Path Sum: " << *maxPathValue;
	cout << endl;

	root = createNode(-15);
	root -> left = createNode(5);
	root -> left -> left = createNode(-8);
	root -> left -> left -> left = createNode(2);
	root -> left -> left -> right = createNode(-3);
	root -> left -> right = createNode(1);
	root -> right = createNode(6);
	root -> right -> left = createNode(3);
	root -> right -> right = createNode(9);
	root -> right -> right -> right = createNode(0);
	root -> right -> right -> right -> left = createNode(4);
	root -> right -> right -> right -> right = createNode(-1);
	root -> right -> right -> right -> right -> left = createNode(10);
	*maxPathValue = INT_MIN;
	getMaxPathSum(root, maxPathValue);
	cout << "Max Path Sum: " << *maxPathValue;
	cout << endl;

	return 0;
}