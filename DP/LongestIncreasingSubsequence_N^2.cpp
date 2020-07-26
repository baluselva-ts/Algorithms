#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int inputSize = 0, maxLength = 0;
	cout << "Enter the number of elements: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	vector<int> LIS(inputSize, 1);
	for (int i = 0; i < inputSize - 1; i++) {
		for (int j = i + 1; j < inputSize; j++) {
			if (inputArray[i] < inputArray[j]) {
				LIS[j] = MAX(LIS[j], LIS[i] + 1);
			}
			maxLength = MAX(maxLength, LIS[j]);
		}
	}
	cout << "Length of Longest Increasing Subsequence is: " << maxLength << endl;
	return 0;
}