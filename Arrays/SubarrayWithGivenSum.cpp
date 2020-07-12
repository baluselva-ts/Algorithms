//https://www.geeksforgeeks.org/find-subarray-with-given-sum/
//works only for positive numbers
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int subArraySum(vector<int> inputArray, int inputSize, int expectedSum) {
	int sum = inputArray[0], start = 0, i;

	for (i = 1; i <= inputSize; i++) {
		while (sum > expectedSum && start < i - 1)
			sum -= inputArray[start++];		
		if (sum == expectedSum) {
			cout << start << " to " << i - 1 << endl;
			return 1;
		}
		if (i < inputSize)
			sum += inputArray[i];
	}

	cout << "Subarray not found" << endl;
	return 0;
}

int main() {
	int inputSize = 0;
	cout << "Enter the array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	int expectedSum = 0;
	cout << "Enter the sum: ";
	cin >> expectedSum;

	subArraySum(inputArray, inputSize, expectedSum);
	return 0;
}