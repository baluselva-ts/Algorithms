//https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void swap(vector<int> &inputArray, int left, int right) {
	int temp = inputArray[left];
	inputArray[left] = inputArray[right];
	inputArray[right] = temp;
}

int main() {
	int firstArraySize, secondArraySize, arraySize;

	cout << "Enter size of first array: ";
	cin >> firstArraySize;

	cout << "Enter size of second array: ";
	cin >> secondArraySize;

	int leftPointer = 0, rightPointer = firstArraySize;

	arraySize = firstArraySize + secondArraySize;

	vector<int> inputArray(arraySize);

	for (int i = 0; i < arraySize; i++)
		cin >> inputArray[i];

	sort(inputArray.begin(), inputArray.end());

	for (int i = 0; i < arraySize; i++) {
		cout << inputArray[i] << " ";
		if (i == firstArraySize - 1)
			cout << endl;
	}
	cout << endl;
}