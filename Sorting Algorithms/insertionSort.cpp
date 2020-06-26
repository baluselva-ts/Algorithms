#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int numberOfElements = 0;
	cout << "Enter the array size: ";
	cin >> numberOfElements;

	int inputArray[numberOfElements];
	cout << "Feed in the input values to search in: " << endl;
	for (int i = 0; i < numberOfElements; i++) {
		cin >> inputArray[i];
	}

	for (int i = 1; i < numberOfElements; i++) {
		int j = i - 1;
		int currentElement = inputArray[i];
		while (j >= 0 && currentElement < inputArray[j]) {
			inputArray[j + 1] = inputArray[j];
			j--;
		}
		inputArray[j + 1] = currentElement;
	}

	for (int i = 0; i < numberOfElements; i++) {
		cout << inputArray[i] << "\t";
	}
	cout << "\n";
	return 0;
}