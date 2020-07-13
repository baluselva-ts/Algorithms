//https://www.geeksforgeeks.org/find-a-partition-point-in-array/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int getPartitionPoint(vector<int> inputArray, int inputSize) {
	vector<int> leftMax = inputArray;
	vector<int> rightMin = inputArray;

	for (int i = 1; i < inputSize; i++) {
		leftMax[i] = MAX(leftMax[i], leftMax[i - 1]);
		rightMin[inputSize - i - 1] = MIN (rightMin[inputSize - i - 1], rightMin[inputSize - i]);
	}

	for (int i = 1; i < inputSize; i++)
		if (inputArray[i] > leftMax[i - 1] && inputArray[i] < rightMin[i + 1])
			return i;
	return -1;
}

int main() {
	int inputSize = 0;
	cout << "Enter array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter array elements: ";

	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	cout << "Partition Point Index: " << getPartitionPoint(inputArray, inputSize) << endl;

	return 0;
}