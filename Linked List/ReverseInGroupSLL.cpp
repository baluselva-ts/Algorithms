#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *createNode(int inputValue) {
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node -> data = inputValue;
	node -> next = NULL;
	return node;
}

struct node *createList(int listSize) {
	int inputValue = 0;
	struct node *head, *temp, *newNode;
	head = createNode(-1);
	temp = head;

	cout << "Enter the list values: ";
	for (int i = 0; i < listSize; i++) {
		cin >> inputValue;
		newNode = createNode(inputValue);
		temp -> next = newNode;
		temp = temp -> next;
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

void reverseList(struct node **head, struct node **tail) {
	struct node *reversedList = NULL, *temp = *head, *reversedHead = *head;
	while (temp -> next != NULL) {
		reversedHead = temp -> next;
		temp -> next = reversedList;
		reversedList = temp;
		temp = reversedHead;
	}
	reversedHead -> next = reversedList;
	*tail = *head;
	*head = reversedHead;
}

struct node *reverseListByGroup(struct node *head, int arraySize, int groupSize) {
	struct node *prefixList = head;
	struct node *start, *end, *suffixList;
	
	for(int i = 0; i < arraySize; i+= groupSize) {
		start = prefixList -> next;
		end = start;
		for (int j = 1; j < groupSize && end -> next; j++) {
			end = end -> next;
		}
		suffixList = end -> next;
		end -> next = NULL;
		reverseList(&start, &end);

		prefixList -> next = start;
		end -> next = suffixList;
		prefixList = end;
	}

	head = head -> next;
	return head;
}

int main() {
	int listSize = 0, data = 0;
	cout << "Enter the list size: ";
	cin >> listSize;

	struct node *head = createList(listSize);
	cout << "List Unchanged: ";
	printList(head -> next);

	int groupSize = 0;
	cout << "Enter the group size:";
	cin >> groupSize;

	struct node *reversedHead = reverseListByGroup(head, listSize, groupSize);
	cout << "List reversed within group of size " << groupSize << ": ";
	printList(reversedHead);

	return 0;
}