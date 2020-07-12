//https://www.geeksforgeeks.org/chocolate-distribution-problem/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void print1DVector(vector<int> inputArray) {
	for (auto number: inputArray)
		cout << number << " ";
	cout << endl;
}

int main() {
	int inputSize = 0, numberOfStudents = 0;
	cout << "Enter input array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	cout << "Enter number of students: ";
	cin >> numberOfStudents;

	sort(inputArray.begin(), inputArray.end());

	int start = 0, end = numberOfStudents - 1;
	int minDifference = INT_MAX;

	while(end < inputSize) {
		minDifference = MIN(minDifference, inputArray[end] - inputArray[start]);
		start++;
		end++;
	}

	cout << "Minimum difference would be: " << minDifference << endl;

	return 0;
}