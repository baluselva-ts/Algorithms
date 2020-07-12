// a space efficient version of https://www.geeksforgeeks.org/count-triplets-such-that-one-of-the-numbers-can-be-written-as-sum-of-the-other-two/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int tripletCount(vector<int> inputArray, int inputSize) {
	map<int, int> frequencies;
	for (int i = 0; i < inputSize; i++)
		frequencies[inputArray[i]] = (frequencies.find(inputArray[i]) != frequencies.end()) ? frequencies[inputArray[i]] + 1 : 1;

	int count = 0;

	if (frequencies.find(0) != frequencies.end())
		count += (frequencies[0] * (frequencies[0] - 1) * (frequencies[0] - 2) / 6);

	for (map<int, int>::iterator i = frequencies.begin(); i != frequencies.end(); i++) {
		if (i -> first != 0) {
			count += (frequencies.find(i -> first) != frequencies.end()) 
						? (frequencies[0] * (frequencies[i -> first] * (frequencies[i -> first] - 1) / 2)) 
						: 0;
			count += (frequencies.find(i -> first) != frequencies.end()) && (frequencies.find(i -> first * 2) != frequencies.end())
						? (frequencies[i -> first * 2] * (frequencies[i -> first] * (frequencies[i -> first] - 1) / 2)) 
						: 0;
		}
	}

	for (map<int, int>::iterator i = frequencies.begin(); i != frequencies.end(); i++) {
		for (auto j = next(i, 1); j != frequencies.end(); j++) {
			if (i -> first != 0 && j -> first != 0) {
				count += (frequencies.find(i -> first) != frequencies.end()) && (frequencies.find(j -> first) != frequencies.end()) && (frequencies.find(i -> first + j -> first) != frequencies.end())
							? (frequencies[i -> first] * frequencies[j -> first] * frequencies[i -> first + j -> first]) 
							: 0;
			}
		}
	}
	return count;

}

int main() {
	int inputSize = 0;
	cout << "Enter the array size: ";
	cin >> inputSize;

	vector<int> inputArray(inputSize);
	cout << "Enter input values: ";
	for (int i = 0; i < inputSize; i++)
		cin >> inputArray[i];

	cout << "Number of triplets: " << tripletCount(inputArray, inputSize) << endl;
}