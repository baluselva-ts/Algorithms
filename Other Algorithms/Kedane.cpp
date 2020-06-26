#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void findMaxSubArray(int inputArray[], int inputSize);

int main() {
	int inputSize = 0;
	cin >> inputSize;

	int inputArray[inputSize];
	for (int i = 0; i < inputSize; i++) {
		cin >> inputArray[i];
	}
	findMaxSubArray(inputArray, inputSize);
	return 0;
}

void findMaxSubArray(int inputArray[], int inputSize) {
	int maxSum = INT_MIN, sum = 0, startIndex = 0, endIndex = 0, start = 0;

	for (int i = 0; i < inputSize; i++) {
		sum += inputArray[i];

		if (sum > maxSum) {
			maxSum = sum;
			endIndex = i;
			startIndex = start;
		}

		if(sum < 0) {
			sum = 0;
			start = i + 1;
		}
	}

	cout << maxSum << endl;
}