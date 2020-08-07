//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void getMaxProfitDays(vector<int> inputArray, int inputSize) {
	int start = 0, i;//, end = 1;

	for (i = 0; i < inputSize - 1; i++) {
		if (inputArray[i] > inputArray[i + 1]) {
			if (i - start >= 1)
				cout << start << " -> " << i << endl;
			start = i + 1;
		}
	}
	if (i - start >= 1)
		cout << start << " -> " << i << endl;
}

int main() {
	int inputSize = 0;
	cout << "Enter array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter array elements: ";

	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	getMaxProfitDays(inputArray, inputSize);

	return 0;
}