//https://practice.geeksforgeeks.org/problems/minimum-swaps/1
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int inputSize = 0, minimumSwaps = 0;
	cout << "Enter input size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	vector<int> isVisited(inputSize, 0);

	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	for (int i = 0, j, swaps; i < inputSize; i++) {
		if (!isVisited[i] && i != inputArray[i]) {
			j = i;
			// cout << "i = " << i << endl;
			swaps = 0;
			while (j != inputArray[j] && !isVisited[inputArray[j]]) {
				// cout << "j = " << j << endl;
				isVisited[inputArray[j]] = 1;
				swaps++;
				j = inputArray[j];
			}
			minimumSwaps += (swaps - 1);
		}
	}

	cout << "Minimum Swaps: " << minimumSwaps << endl;
}