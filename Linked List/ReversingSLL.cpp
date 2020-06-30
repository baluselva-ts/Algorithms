#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct node{
	int inputValue;
	struct node *next;
};

struct node *createNode(int inputValue) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> inputValue = inputValue;
	node -> next = NULL;
	return node;
}

struct node *createList(int listSize) {
	int inputValue = 0;
	struct node *head, *temp, *newNode;

	cout << "Enter the list values: ";
	for (int i = 0; i < listSize; i++) {
		cin >> inputValue;
		if (i == 0) {
			head = createNode(inputValue);
			temp = head;
		} else {
			newNode = createNode(inputValue);
			temp -> next = newNode;
			temp = temp -> next;
		}
	}
	return head;
}

void printList(struct node *head) {
	struct node *temp = head;

	while (temp != NULL) {
		cout << temp -> inputValue << " ";
		temp = temp -> next;
	}
	cout << endl;
}

struct node *reverseList(struct node *head) {
	struct node *reversedList = NULL, *temp = head, *reversedHead = head;
	while (temp -> next != NULL) {
		reversedHead = temp -> next;
		temp -> next = reversedList;
		reversedList = temp;
		temp = reversedHead;
	}
	reversedHead -> next = reversedList;
	return reversedHead;
}

int main() {
	int listSize = 0, inputValue = 0;
	cout << "Enter the list size: ";
	cin >> listSize;

	struct node *head = createList(listSize);
	cout << "List Unchanged: ";
	printList(head);

	struct node *headReversed = reverseList(head);
	cout << "List in Reverse Order: ";
	printList(headReversed);

	return 0;
}