//https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
#include <iostream>

using namespace std;

void swap(string &inputString, int left, int right) {
	char temp = inputString[left];
	inputString[left] = inputString[right];
	inputString[right] = temp;
}

void reverseString(string &inputString, int left, int right) {
	for (; left < right; left++, right--)
		swap(inputString, left, right);
}

int main() {
	string inputString;
	int stringLength;

	cout << "Enter input string with words delimited by period(.)" << endl;
	cin >> inputString;
	reverseString(inputString, 0, inputString.length() - 1);

	for (int i = 0, start = 0; i <= inputString.length(); i++) {
		if (i == inputString.length())
			reverseString(inputString, start, i - 1);
		else if (inputString[i] == '.') {
			reverseString(inputString, start, i - 1);
			start = i + 1;
		}
	}
	cout << inputString << endl;
	return 0;
}