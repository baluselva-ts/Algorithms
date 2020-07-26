//https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include <iostream>
#include <vector>
#include <map>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

void printLengthOfLIS(vector<int> inputArray, int inputSize) {
	vector<int> length;

	for (int i = 0; i < inputSize; i++) {
		int lowerBound = lower_bound(length.begin(), length.end(), inputArray[i]) - length.begin();
		if (lowerBound == 0 && length.size())
			length[lowerBound] = inputArray[i];
		else if (lowerBound == 0 || lowerBound >= length.size())
			length.push_back(inputArray[i]);
		else
			length[lowerBound] = inputArray[i];
	}
	cout << "Length of Longest Increasing Subsequence is: " << length.size() << endl;
}

int main() {
	int inputSize = 0, maxLength = 0;
	cout << "Enter the number of elements: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];
	vector<int> temp;
	cout << lower_bound(temp.begin(), temp.end(), 5) - temp.begin() << endl;
	printLengthOfLIS(inputArray, inputSize);
	return 0;
}