//https://practice.geeksforgeeks.org/problems/largest-number-possible/0
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

void printLargestNumber(int numberOfDigits, int totalSum) {
	int sumSoFar = 0, maxNumber = 0;
	for (int i = 0; i < numberOfDigits; i++) {
		int thisNumber = MIN(9, totalSum - sumSoFar);
		maxNumber = maxNumber * 10 + thisNumber;
		sumSoFar += thisNumber;
	}
	if (sumSoFar == totalSum) {
		cout << "Max number that can be formed with " << numberOfDigits << " digits with sum of digits as " << totalSum;
		cout << " is: " << maxNumber << endl;
	} else
		cout << "Can't generate a number for given inputs" << endl;
}

int main() {
	int numberOfDigits = 0, totalSum = 0;
	cout << "Enter number of digits and total sum: ";
	cin >> numberOfDigits >> totalSum;
	printLargestNumber(numberOfDigits, totalSum);
	return 0;
}