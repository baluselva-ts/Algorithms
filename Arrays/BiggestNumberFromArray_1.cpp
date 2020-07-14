#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int strCompare(string left, string right) {
	return left.append(right).compare(right.append(left)) > 0;
}

int main() {
	int inputSize = 0;
	cout << "Enter array size: ";
	cin >> inputSize;

	vector<string> inputArray(inputSize);
	cout << "Enter array elements: ";

	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	sort(inputArray.begin(), inputArray.end(), strCompare);

	for (auto str: inputArray)
		cout << str;
	cout << endl;
}