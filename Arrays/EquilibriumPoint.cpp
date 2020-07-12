//https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
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

int printFirstEquilibriumPoint(vector<int> inputArray, int inputSize) {
	vector<int> sumSoFarForward = inputArray;
	vector<int> sumSoFarBackward = inputArray;

	for (int i = 1; i < inputSize; i++) {
		sumSoFarForward[i] += sumSoFarForward[i - 1];
		sumSoFarBackward[inputSize - 1 - i] += sumSoFarBackward[inputSize - i];
	}

	for (int i = 0; i < inputSize; i++) {
		if (sumSoFarForward[i] == sumSoFarBackward[i]) {
			cout << "Equilibrium Index: " << i << endl;
			return i;
		}
	}
	cout << "There is no Equilibrium Index" << endl;
	return -1;
}

int main() {
	int inputSize = 0;
	cout << "Enter Input Size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	printFirstEquilibriumPoint(inputArray, inputSize);

	return 0;
}