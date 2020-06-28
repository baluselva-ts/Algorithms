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

int getListLength(struct node *head) {
	struct node *temp = head;
	int length = 0;

	while(temp) {
		length++;
		temp = temp -> next;
	}

	return length;
}

struct node *getIntersectionPoint(struct node *headFirst, struct node *headSecond) {
	int lengthFirst = getListLength(headFirst);
	int lengthSecond = getListLength(headSecond);
	int difference = abs(lengthFirst - lengthSecond);
	
	if(lengthFirst > lengthSecond) {
		while (difference > 0) {
			headFirst = headFirst -> next;
			difference--;
		}
	}else if (lengthSecond > lengthFirst) {
		while (difference > 0) {
			headSecond = headSecond -> next;
			difference--;
		}
	}

	while (headFirst != NULL) {
		if (headFirst == headSecond) {
			return headFirst;
		}
		headFirst = headFirst -> next;
		headSecond = headSecond -> next;
	}
	return NULL;
}

int main() {
	int listSize = 0;
	cout << "Enter the first list size(>=4): ";
	cin >> listSize;

	struct node *headFirst = createList(listSize);
	cout << "First List Unchanged: ";
	printList(headFirst);

	struct node *headSecond = createNode(11);
	headSecond -> next = createNode(12);
	headSecond -> next -> next = createNode(13);
	headSecond -> next -> next -> next = createNode(14);
	headSecond -> next -> next -> next -> next = createNode(15);
	headSecond -> next -> next -> next -> next -> next = createNode(16);
	headSecond -> next -> next -> next -> next -> next -> next = headFirst -> next -> next -> next;
	cout << "Second List Unchanged: ";
	printList(headSecond);

	struct node *intersectionPoint = getIntersectionPoint(headFirst, headSecond);
	if (intersectionPoint) {
		cout << "Both the lists are intersecting at " << intersectionPoint -> data << endl;
	} else {
		cout << "Lists are not intersecting" << endl;
	}
	return 0;
}