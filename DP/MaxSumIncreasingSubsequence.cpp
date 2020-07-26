//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int inputSize = 0;
	cout << "Enter the number of elements: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	vector<int> maxSumLIS(inputSize);
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; maxSumLIS[i] = inputArray[i], i++)
		cin >> inputArray[i];

	int maxSum = inputArray[0];
	for (int i = 0; i < inputSize - 1; i++) {
		for (int j = i + 1; j < inputSize; j++) {
			if (inputArray[i] < inputArray[j])
				maxSumLIS[j] = MAX(maxSumLIS[j], maxSumLIS[i] + inputArray[j]);
			maxSum = MAX(maxSum, maxSumLIS[i]);
		}
	}
	cout << "Maximum Sum of Increasing Subsequence is: " << maxSum << endl;
	return 0;
}