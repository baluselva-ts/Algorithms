#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void mergeSort(int *inputArray, int start, int end);
void merge(int *inputArray, int start, int mid, int end);
int binarySearchIterative(int *inputArray, int elementToSearch, int start, int end);
int binarySearchRecursive(int *inputArray, int elementToSearch, int start, int end);

int main() {
	int numberOfElements = 0;
	int elementToSearch = 0;
	cin >> numberOfElements;

	int inputArray[numberOfElements];
	for (int i = 0; i < numberOfElements; i++) {
		cin >> inputArray[i];
	}
	cout << "Element to search: ";
	cin >> elementToSearch;

	mergeSort(inputArray, 0, numberOfElements - 1);

	cout << endl << "Sorted Array:\t";
	for (int i = 0; i < numberOfElements; i++) {
			cout << inputArray[i] << "\t";
		}
	cout << endl;

	int index = binarySearchRecursive(inputArray, elementToSearch, 0, numberOfElements - 1);
	cout << "Index: " << index << endl;
	(index != -1) ? cout << elementToSearch << " is at " << index + 1 << " position" << endl : cout << elementToSearch << " not found" << endl;

	return 0;
}

void mergeSort(int *inputArray, int start, int end) {
	if(start < end) {
		int mid = start + (end - start) / 2;
		mergeSort(inputArray, start, mid);
		mergeSort(inputArray, mid + 1, end);
		merge(inputArray, start, mid, end);
	}
}

void merge(int *inputArray, int start, int mid, int end) {
	int leftArraySize = (mid - start) + 2;
	int rightArraySize = (end - mid) + 1;
	int leftArray[leftArraySize];
	int rightArray[rightArraySize];
	int i, j, leftArrayIndex, rightArrayIndex;
	for (j = 0, i = start; i <= mid; i++, j++) {
		leftArray[j] = inputArray[i];
	}
	leftArray[j] = INT_MAX;
	for(j = 0, i = mid + 1; i <= end; i++, j++ ) {
		rightArray[j] = inputArray[i];
	}
	rightArray[j] = INT_MAX;

	for (i = start, leftArrayIndex = 0, rightArrayIndex = 0; i <= end; i++) {
		if (rightArray[rightArrayIndex] < leftArray[leftArrayIndex]) {
			inputArray[i] = rightArray[rightArrayIndex++];
		} else {
			inputArray[i] = leftArray[leftArrayIndex++];
		}
	}
}

int binarySearchIterative(int *inputArray, int elementToSearch, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2; 
		if(inputArray[mid] == elementToSearch) {
			return mid;
		} else if (inputArray[mid] < elementToSearch) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}

	}
	return -1;
}

int binarySearchRecursive(int *inputArray, int elementToSearch, int start, int end) {
	int mid = (start + end) / 2;
	cout << "Mid Value: " << inputArray[mid] << endl;
	if(inputArray[mid] == elementToSearch) {
		return mid;
	}
	if(start <= end) {
		if (inputArray[mid] < elementToSearch) {
			binarySearchRecursive(inputArray, elementToSearch, mid + 1, end);
		} else {
			binarySearchRecursive(inputArray, elementToSearch, start, mid - 1);
		}
	} else {
		return -1;
	}
}

















