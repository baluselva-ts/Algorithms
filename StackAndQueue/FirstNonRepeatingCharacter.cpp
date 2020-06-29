//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

#include <iostream>
#include <queue>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct myQueue {
	queue<char> nonRepeatingChars;

	char front() {
		return (nonRepeatingChars.size()) ? nonRepeatingChars.front() : 'X';
	}

	void push(char character) {
		nonRepeatingChars.push(character);
	}

	void pop() {
		if (nonRepeatingChars.size()) {
			nonRepeatingChars.pop();
		}
	}
};

int main() {
	myQueue nonRepeatingChars;
	string inputString;
	cout << "Enter the input string:";
	cin >> inputString;
	int inputLength = inputString.size();

	for (int i = 0 ; i < inputLength; i++) {
		if (nonRepeatingChars.front() == inputString[i]) {
			cout << "-1 ";
			nonRepeatingChars.pop();
		}
		else {
			nonRepeatingChars.push(inputString[i]);
			cout << nonRepeatingChars.front() << " ";
		}
	}
	cout << endl;
	return 0;
}