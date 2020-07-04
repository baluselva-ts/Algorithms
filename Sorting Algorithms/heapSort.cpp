#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void swap(vector<int> &inputArray, int i, int j) {
	int temp = inputArray[i];
	inputArray[i] = inputArray[j];
	inputArray[j] = temp;
}

void heapifyNewElement(vector<int> &inputArray, int i) {
	int currentIndex = i;
	int parentIndex = currentIndex / 2;
	while (parentIndex >=0 && inputArray[currentIndex] < inputArray[parentIndex]) {
		swap (inputArray, currentIndex, parentIndex);
		currentIndex = parentIndex;
		parentIndex = currentIndex / 2;
	}
}

void printVector(vector<int> inputArray) {
	for (auto element: inputArray)
		cout << element << " ";
	cout << endl;
}

void heapify(vector<int> &inputArray, int parentIndex) {
	if (parentIndex > inputArray.size() || ((parentIndex * 2) + 1) >= inputArray.size())
		return;
	int leftChild, rightChild, parent;
	heapify(inputArray, ((parentIndex * 2) + 2));
	heapify(inputArray, ((parentIndex * 2) + 1));
	parent = inputArray[parentIndex];
	if (((parentIndex * 2) + 2) < inputArray.size()) {
		rightChild = inputArray[(parentIndex * 2) + 2];
		leftChild = inputArray[(parentIndex * 2) + 1];
		if (leftChild < rightChild && leftChild < parent)
			swap(inputArray, (parentIndex * 2) + 1, parentIndex);
		else if (rightChild < leftChild && rightChild < parent)
			swap(inputArray, (parentIndex * 2) + 2, parentIndex);
	} else if (leftChild < parent)
		swap(inputArray, (parentIndex * 2) + 1, parentIndex);
}

void heapSort(vector<int> &inputArray) {
	vector<int> sortedArray;
	int i = 0;
	while (inputArray.size()) {
		sortedArray.push_back(inputArray[0]);
		inputArray[0] = inputArray[inputArray.size() - 1];
		inputArray.resize(inputArray.size() - 1);
		if (inputArray.size()) {
			heapify(inputArray, 0);
		}
		i++;
	}
	inputArray = sortedArray;
}

int main() {
	int numberOfElements = 0;
	cout << "Enter the array size: ";
	cin >> numberOfElements;

	vector<int> inputArray;
	cout << "Feed in the input values to search in: " << endl;
	for (int i = 0, inputValue; i < numberOfElements; i++) {
		cin >> inputValue;
		inputArray.push_back(inputValue);
		heapifyNewElement(inputArray, i);
	}
	heapSort(inputArray);
	printVector(inputArray);
	return 0;
}