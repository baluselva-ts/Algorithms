//https://www.geeksforgeeks.org/trapping-rain-water/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int inputSize = 0, rainwater = 0;
	cout << "Enter input size: ";
	cin >> inputSize;
	
	vector<int> inputArray(inputSize);
	vector<int> maxForward(inputSize);
	vector<int> maxBackward(inputSize);
	
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	int maxRight = INT_MIN, maxLeft = INT_MIN;

	for (int i = 0; i < inputSize; i++) {
		maxRight = MAX(maxRight, inputArray[i]);
		maxForward[i] = maxRight;

		maxLeft = MAX(maxLeft, inputArray[inputSize - i - 1]);
		maxBackward[inputSize - i - 1] = maxLeft;
	}

	for (int i = 0; i < inputSize; i++)
		rainwater += (MIN(maxForward[i], maxBackward[i]) - inputArray[i]);

	cout << "Maximum water we can trap: " << rainwater << endl;
}