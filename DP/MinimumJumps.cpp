//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
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
	vector<int> minJumps(inputSize, INT_MAX);
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	minJumps[0] = 0;
	for (int i = 0; i < inputSize - 1; i++)
		if (minJumps[i] != INT_MAX)
			for (int j = 1, k = i + 1; j <= inputArray[i] && k < inputSize; j++, k++)
				minJumps[k] = MIN(minJumps[k], minJumps[i] + 1);

	if (minJumps[inputSize - 1] == INT_MAX)
		cout << "Can't reach the end" << endl;
	else
		cout << "Can reach the end with minimum jumps of: " << minJumps[inputSize - 1] << endl;
	return 0;
}