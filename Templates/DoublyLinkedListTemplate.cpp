#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct node{
	int value;
	struct node *previous;
	struct node *next;
};

struct node *createNode(int value) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> value = value;
	node -> previous = NULL;
	node -> next = NULL;
	return node;
}

int main() {
	return 0;
}