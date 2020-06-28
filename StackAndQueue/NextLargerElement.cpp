//https://practice.geeksforgeeks.org/problems/next-larger-element/0

#include <iostream>
#include <stack>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int inputSize = 0, value = 0;
	cout << "Enter number of Input elements:";
	cin >> inputSize;

	vector<int> inputVector;
	cout << "Enter Input Elements: ";
	for (int i = 0; i < inputSize; i++) {
		cin >> value;
		inputVector.push_back(value);
	}

	reverse(inputVector.begin(), inputVector.end());

	vector<int> nextMax;
	stack<int> intStack;

	int i = 0;
	while (i < inputSize) {
		if (intStack.size() && inputVector[i] >= intStack.top()) {
			intStack.pop();
		} else if (intStack.size() && inputVector[i] < intStack.top()) {
			nextMax.push_back(intStack.top());
			intStack.push(inputVector[i]);
			i++;
		}
		if(intStack.size() == 0) {
			nextMax.push_back(-1);
			intStack.push(inputVector[i]);
			i++;
		}
	}

	reverse(nextMax.begin(), nextMax.end());

	for (int i = 0; i < inputSize; i++) {
		cout << nextMax[i] << " ";
	}
	cout << endl;
	return 0;
}