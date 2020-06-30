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

bool detectLoop(struct node *head) {
	struct node *slowHead = head, *fastHead = head;
	if (slowHead != NULL && fastHead != NULL) {
		while (fastHead -> next != NULL) {
			slowHead = slowHead -> next;
			fastHead = fastHead -> next -> next;
			if (slowHead == fastHead) {
				return true;
			}
		}
	}
	return false;
}

void detectLoopValueAndBreak(struct node *head) {
	struct node *slowHead = head, *fastHead = head;
	while (fastHead -> next != NULL) {
		slowHead = slowHead -> next;
		fastHead = fastHead -> next -> next;
		if(slowHead == fastHead) {
			break;
		}
	}
	if (slowHead == fastHead) {
		slowHead = head;
		while (slowHead -> next != fastHead -> next) {
			slowHead = slowHead -> next;
			fastHead = fastHead -> next;
		}
	}
	cout << slowHead -> data << " and " << fastHead -> data << " are converging at " << slowHead -> next -> data << endl;
	cout << "Breaking loop at " << fastHead -> data << endl;
	fastHead -> next = NULL;
	printList(head);
}

int main() {
	struct node *head = createNode(1);
	head -> next = createNode(2);
	head -> next -> next = createNode(3);
	head -> next -> next -> next = createNode(4);
	head -> next -> next -> next -> next = createNode(5);
	head -> next -> next -> next -> next -> next = createNode(6);
	head -> next -> next -> next -> next -> next -> next = createNode(7);
	head -> next -> next -> next -> next -> next -> next -> next = createNode(8);
	head -> next -> next -> next -> next -> next -> next -> next -> next = head -> next -> next -> next;
	// head -> next -> next -> next -> next -> next -> next -> next -> next = createNode(9);
	if (detectLoop(head)) {
		cout << "Loop Detected. ";
		detectLoopValueAndBreak(head);
	}
	else {
		cout << "List: ";
		printList(head);
	}
	return 0;
}