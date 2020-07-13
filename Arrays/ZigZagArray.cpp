//https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0
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

void rearrangeArray(vector<int> &inputArray, int inputSize) {
	for (int i = 1; i < inputSize; i++)
		if ((i % 2 == 1 && inputArray[i] < inputArray[i - 1]) || (i % 2 == 0 && inputArray[i] > inputArray[i - 1]))
			swap(inputArray, i - 1, i);
}

int main() {
	int inputSize = 0;
	cout << "Enter array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter array elements: ";

	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	rearrangeArray(inputArray, inputSize);

	for (auto number: inputArray)
		cout << number << " ";
	cout << endl;

	return 0;
}