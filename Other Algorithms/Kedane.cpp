#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void findMaxSubArray(int inputArray[], int numberOfElements);

int main() {
	int numberOfElements = 0;
	cout << "Enter the array size: ";
	cin >> numberOfElements;

	int inputArray[numberOfElements];
	cout << "Feed in the input values to search in: " << endl;
	for (int i = 0; i < numberOfElements; i++) {
		cin >> inputArray[i];
	}
	findMaxSubArray(inputArray, numberOfElements);
	return 0;
}

void findMaxSubArray(int inputArray[], int numberOfElements) {
	int maxSum = INT_MIN, sum = 0, startIndex = 0, endIndex = 0, start = 0;

	for (int i = 0; i < numberOfElements; i++) {
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