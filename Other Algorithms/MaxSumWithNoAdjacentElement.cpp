//https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;


int getMaxSum(vector<int> inputVector, int numberOfElements) {
	int sumIncludingCurrentElement = 0, sumExcludingCurrentElement = 0;
	if (numberOfElements <= 0)
		return inputVector[0];
	else {
		int sumIncludingPreviousElement = inputVector[0], sumExcludingPreviousElement = 0;
		for (int i = 1; i < numberOfElements; i++) {
			sumIncludingCurrentElement = sumExcludingPreviousElement + inputVector[i];
			sumExcludingCurrentElement = MAX(sumIncludingPreviousElement, sumExcludingPreviousElement);
			sumIncludingPreviousElement = sumIncludingCurrentElement;
			sumExcludingPreviousElement = sumExcludingCurrentElement;
		}
	}
	return MAX(sumIncludingCurrentElement, sumExcludingCurrentElement);
}

int main() {
	int numberOfElements = 0;
	cout << "Enter number of Elements: ";
	cin >> numberOfElements;

	vector<int> inputVector(numberOfElements);
	cout << "Enter input elements: ";
	for (int i = 0; i < numberOfElements; i++)
		cin >> inputVector[i];

	cout << "Max sum: " << getMaxSum(inputVector, numberOfElements) << endl;
	return 0;
}