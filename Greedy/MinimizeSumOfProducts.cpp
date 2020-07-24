//https://practice.geeksforgeeks.org/problems/minimize-the-sum-of-product/0
#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int inputSize = 0, sumOfProduct = 0;
	cout << "Enter size of the input arrays: ";
	cin >> inputSize;

	priority_queue<int> listA;
	priority_queue<int, vector<int>, greater<int> > listB;

	cout << "Enter values for listA: ";
	for (int i = 0, value; i < inputSize; i++) {
		cin >> value;
		listA.push(value);
	}

	cout << "Enter values for listA: ";
	for (int i = 0, value; i < inputSize; i++) {
		cin >> value;
		listB.push(value);
	}

	for (int i = 0; i < inputSize; i++, listA.pop(), listB.pop())
		sumOfProduct += (listA.top() * listB.top());

	cout << "Minimum sum of product we can get is: " << sumOfProduct << endl;
	return 0;
}