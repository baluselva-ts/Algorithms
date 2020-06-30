#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long
#define NODE struct node*

using namespace std;

struct node{
	int data;
	NODE left;
	NODE right;
	int horizontalDistance;
	int level;
};

NODE createNode(int value) {
	NODE node = (struct node*)malloc(sizeof(struct node));
	node -> data = value;
	node -> left = NULL;
	node -> right = NULL;
	node -> horizontalDistance = 0;
	node -> level = 0;
	return node;
}

void traversePreorder(NODE root) {
	if(!root)
		return;
	cout << root -> data << " ";
	traversePreorder(root -> left);
	traversePreorder(root -> right);
}

void traverseInorder(NODE root) {
	if(!root)
		return;
	traverseInorder(root -> left);
	cout << root -> data << " ";
	traverseInorder(root -> right);
}

void traversePostorder(NODE root) {
	if(!root)
		return;
	traversePostorder(root -> left);
	traversePostorder(root -> right);
	cout << root -> data << " ";
}

void traverseLevelOrder(NODE root) {
	if(!root)
		return;

	queue<NODE> traversalQueue;
	traversalQueue.push(root);
	while (traversalQueue.size()) {
		if((traversalQueue.front()) -> left)
			traversalQueue.push((traversalQueue.front()) -> left);
		if((traversalQueue.front()) -> right)
			traversalQueue.push((traversalQueue.front()) -> right);
		cout << (traversalQueue.front()) -> data << " ";
		traversalQueue.pop();
	}
}

map< int, vector<int> > groupNodesByLevel(NODE root) {
	map< int, vector<int> > nodesAtEachLevel;
	if (root) {
		queue<NODE> traversalQueue;
		traversalQueue.push(root);
		while (traversalQueue.size()) {
			NODE front = traversalQueue.front();
			if(front -> left) {
				front -> left -> level = (front -> level) + 1;
				traversalQueue.push(front -> left);
			}
			if(front -> right) {
				front -> right -> level = (front -> level) + 1;
				traversalQueue.push(front -> right);
			}
			nodesAtEachLevel[front -> level].push_back(front -> data);
			traversalQueue.pop();
		}
	}
	return nodesAtEachLevel;
}

void traverseLevelOrderSpiral(NODE root) {
	map< int, vector<int> > nodeMap = groupNodesByLevel(root);
	
	for (map< int, vector<int> >::iterator itr = nodeMap.begin(); itr != nodeMap.end(); itr++) {
		vector<int> nodesAtThisLevel = itr -> second;
		int numberOfNodes = nodesAtThisLevel.size();

		if ((itr -> first) % 2 == 1)
			reverse(nodesAtThisLevel.begin(), nodesAtThisLevel.end());
		
		for (int i = 0; i < numberOfNodes; i++) {
			cout << nodesAtThisLevel[i] << " ";
		}
		// if (next(itr, 1) != nodeMap.end()) {
		// 	cout << "$ ";
		// } 
	}

}

bool needsToBePrinted(int i, int size, string type) {
	if (type == "TOP") {
		return i == 0;
	} else if (type == "BOTTOM") {
		return (i == size - 1);
	}
	return true;
}

map< int, vector<int> > groupNodesByHorizontalDistance(NODE root) {
	map< int, vector<int> > nodesAtHorizontalDistance;
	if (root) {
		queue<NODE> traversalQueue;
		traversalQueue.push(root);
		while (traversalQueue.size()) {
			NODE front = traversalQueue.front();
			if(front -> left) {
				front -> left -> horizontalDistance = (front -> horizontalDistance) - 1;
				traversalQueue.push(front -> left);
			}
			if(front -> right) {
				front -> right -> horizontalDistance = (front -> horizontalDistance) + 1;
				traversalQueue.push(front -> right);
			}
			nodesAtHorizontalDistance[front -> horizontalDistance].push_back(front -> data);
			traversalQueue.pop();
		}
	}
	return nodesAtHorizontalDistance;
}

void printNodesInVerticalOrder(map< int, vector<int> > nodeMap, string view) {
	map< int, vector<int> >::iterator itr;

	for (map< int, vector<int> >::iterator itr = nodeMap.begin(); itr != nodeMap.end(); itr++) {
		int numberOfNodes = (itr -> second).size();
		for (int i = 0; i < numberOfNodes; i++) {
			if (needsToBePrinted(i, numberOfNodes, view))
				cout << (itr -> second)[i] << " ";
		}
		if (next(itr, 1) != nodeMap.end()) {
			cout << "$ ";
		} 
	}
}

void traverseVerticalorder(NODE root) {
	printNodesInVerticalOrder(groupNodesByHorizontalDistance(root), "");
}

void printLeftView(NODE root) {
	if (!root) {
		return;
	}

	queue<NODE> leftView;
	leftView.push(root);

	while(!leftView.empty()) {
		int nodes = leftView.size();

		for (int i = 1; i <= nodes; i++) {
			NODE temp = leftView.front();
			leftView.pop();

			if (i == 1) {
				cout << temp -> data << " ";
			}

			if (temp -> left) {
				leftView.push(temp -> left);
			}

			if (temp -> right) {
				leftView.push(temp -> right);
			}
		}
	}
}

void printRightView(NODE root) {
	if (!root) {
		return;
	}

	queue<NODE> leftView;
	leftView.push(root);

	while(!leftView.empty()) {
		int nodes = leftView.size();

		for (int i = 1; i <= nodes; i++) {
			NODE temp = leftView.front();
			leftView.pop();

			if (i == nodes) {
				cout << temp -> data << " ";
			}

			if (temp -> left) {
				leftView.push(temp -> left);
			}

			if (temp -> right) {
				leftView.push(temp -> right);
			}
		}
	}
}

void printTopView(NODE root) {
	printNodesInVerticalOrder(groupNodesByHorizontalDistance(root), "TOP");
}

void printBottomView(NODE root) {
	printNodesInVerticalOrder(groupNodesByHorizontalDistance(root), "BOTTOM");
}

void traverse(NODE root) {
	cout << "Pre - Order: ";
	traversePreorder(root);
	cout << endl;

	cout << "In - Order: ";
	traverseInorder(root);
	cout << endl;

	cout << "Post - Order: ";
	traversePostorder(root);
	cout << endl;

	cout << "Level - Order: ";
	traverseLevelOrder(root);
	cout << endl;

	cout << "Level - Order Spiral: ";
	traverseLevelOrderSpiral(root);
	cout << endl;

	cout << "Vertical - Order: ";
	traverseVerticalorder(root);
	cout << endl;

	cout << "Left - View: ";
	printLeftView(root);
	cout << endl;

	cout << "Right - View: ";
	printRightView(root);
	cout << endl;

	cout << "Top - View: ";
	printTopView(root);
	cout << endl;

	cout << "Bottom - View: ";
	printBottomView(root);
	cout << endl;
}

int main() {
	NODE root = createNode(4);
	root -> left = createNode(2);
	root -> right = createNode(6);
	root -> left -> left = createNode(1);
	root -> left -> right = createNode(3);
	root -> right -> left = createNode(5);
	root -> right -> right = createNode(7);
	traverse(root);
	cout << endl;

	root = createNode(1);
	root -> right = createNode(2);
	root -> right -> right = createNode(3);
	root -> right -> right -> right = createNode(4);
	root -> right -> right -> right -> right = createNode(5);
	root -> right -> right -> right -> right -> right = createNode(6);
	root -> right -> right -> right -> right -> right -> right = createNode(7);
	traverse(root);
	cout << endl;

	root = createNode(3);
	root -> left = createNode(1);
	root -> left -> right = createNode(2);
	root -> right = createNode(5);
	root -> right -> left = createNode(4);
	root -> right -> right = createNode(7);
	root -> right -> right -> left = createNode(6);
	traverse(root);
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
	traverse(root);
	cout << endl;

	return 0;
}