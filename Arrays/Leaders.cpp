//https://www.geeksforgeeks.org/leaders-in-an-array/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int inputSize;
	cout << "Enter the input array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);

	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	int max = INT_MIN;

	for (int i = inputSize - 1; i>= 0; i--) {
		max = MAX(max, inputArray[i]);
		if (max == inputArray[i])
			cout << inputArray[i] << " ";
	}
	cout << endl;
}