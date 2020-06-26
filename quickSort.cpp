#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void quickSort(int *inputArray, int start, int end);
int partition(int *inputArray, int start, int end);
void swap(int *inputArray, int left, int right);

int main() {
	int numberOfElements = 0;
	cin >> numberOfElements;

	int inputArray[numberOfElements];
	for (int i = 0; i < numberOfElements; i++) {
		cin >> inputArray[i];
	}

	quickSort(inputArray, 0, numberOfElements - 1);

	for (int i = 0; i < numberOfElements; i++) {
		cout << inputArray[i] << "\t";
	}
	cout << endl;
	return 0;
}

void quickSort(int *inputArray, int start, int end) {
	if(start < end) {
		int mid = partition(inputArray, start, end);
		quickSort(inputArray, start, mid - 1);
		quickSort(inputArray, mid + 1, end);
	}
}

int partition(int *inputArray, int start, int end) {
	int pivotValue = inputArray[end];
	int left = start - 1;
	int right = start;
	while (right < end) {
		if (inputArray[right] <= pivotValue) {
			left++;
			swap(inputArray, left, right);
		}
		right++;
	}
	swap(inputArray, ++left, end);
	return left;
}

void swap(int *inputArray, int left, int right) {
	int swapValue = inputArray[left];
	inputArray[left] = inputArray[right];
	inputArray[right] = swapValue;
}