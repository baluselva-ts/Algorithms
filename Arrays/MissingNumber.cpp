//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int getMissingNumber(vector<int> inputArray, int inputSize) {
	int missedNumber = 0;

	for (int i = 0; i < inputSize - 1; i++)
		missedNumber = missedNumber ^ inputArray[i];

	for (int i = 1; i <= inputSize; i++)
		missedNumber = missedNumber ^ i;

	return missedNumber;
}

int main() {
	int inputSize = 0;
	cout << "Enter the array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize - 1);
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize - 1; i++)
		cin >> inputArray[i];

	cout << "Missing number is: " << getMissingNumber(inputArray, inputSize) << endl;
}