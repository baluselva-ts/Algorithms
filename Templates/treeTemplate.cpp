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

void placeHolder(NODE root) {
	
}

int main() {

	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	placeHolder(root);
	cout << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	placeHolder(root);
	cout << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	placeHolder(root);
	cout << endl;

	return 0;
}