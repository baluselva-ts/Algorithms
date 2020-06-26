#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct node{
	int value;
	struct node *left;
	struct node *right;
};

struct node *createNode(int value) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> value = value;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

struct node *createNode(int value, struct *leftNode, struct *rightNode) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> value = value;
	node -> left = leftNode;
	node -> right = rightNode;
	return node;
}

int main() {
	return 0;
}