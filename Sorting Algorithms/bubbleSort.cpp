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

	for (int i = 0; i < numberOfElements; i++) {
		bool swapped = false;
		for (int j = 0; j < numberOfElements - 1; j++) {
			if (inputArray[j + 1] < inputArray[j]) {
				inputArray[j] = inputArray[j] + inputArray[j + 1];
				inputArray[j + 1] = inputArray[j] - inputArray[j + 1];
				inputArray[j] = inputArray[j] - inputArray[j + 1];
				swapped = true;
			}
		}
		if(!swapped) {
			break;
		}
	}

	for (int i = 0; i < numberOfElements; i++) {
		cout << inputArray[i] << "\t";
	}
	cout << "\n";
	return 0;
}