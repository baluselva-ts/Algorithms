//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
#include <iostream>

using namespace std;

void permute(string inputString, int start, int end, int &count) {
	if (start == end) {
		cout << inputString << endl;
		count++;
	}
	else {
		for (int i = start; i <= end; i++) {
			swap(inputString[start], inputString[i]);
			permute(inputString, start + 1, end, count);
			swap(inputString[start], inputString[i]);
		}
	}
}

int main() {
	string inputString;
	int stringLength, count = 0;

	cout << "Enter input string" << endl;
	cin >> inputString;

	permute(inputString, 0, inputString.length() - 1, count);
	cout << count << endl;

	return 0;
}