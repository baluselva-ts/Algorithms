#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void mergeSort(int *inputArray, int start, int end);
void merge(int *inputArray, int start, int mid, int end);

int main() {
	int numberOfElements = 0;
	cout << "Enter the array size: ";
	cin >> numberOfElements;

	int inputArray[numberOfElements];
	cout << "Feed in the input values to search in: " << endl;
	for (int i = 0; i < numberOfElements; i++) {
		cin >> inputArray[i];
	}

	mergeSort(inputArray, 0, numberOfElements - 1);

	for (int i = 0; i < numberOfElements; i++) {
		cout << inputArray[i] << "\t";
	}
	cout << endl;
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