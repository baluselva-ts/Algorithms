#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *createNode(int value) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> data = value;
	node -> next = NULL;
	return node;
}

struct node *createList(int listSize) {
	int value = 0;
	struct node *head, *temp, *newNode;

	cout << "Enter the list values: " << endl;
	for (int i = 0; i < listSize; i++) {
		cin >> value;
		if (i == 0) {
			head = createNode(value);
			temp = head;
		} else {
			newNode = createNode(value);
			temp -> next = newNode;
			temp = temp -> next;
		}
	}
	return head;
}

void printList(struct node *head) {
	struct node *temp = head;

	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main() {
	int listSize = 0;
	cout << "Enter the list size: ";
	cin >> listSize;

	struct node *head = createList(listSize);
	cout << "List Unchanged: ";
	printList(head);

	return 0;
}