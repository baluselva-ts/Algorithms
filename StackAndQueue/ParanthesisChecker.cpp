//https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

#include <iostream>
#include <stack>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int i = 0;
	string inputString;
	cout << "Enter the input paranthesis to check:";
	cin >> inputString;

	stack<char> charStack;

	for (; i < inputString.size(); i++) {
		if (inputString[i] == '[' || inputString[i] == '(' || inputString[i] == '{')
			charStack.push(inputString[i]);
		else if (inputString[i] == ']' && charStack.size() && charStack.top() == '[')
			charStack.pop();
		else if (inputString[i] == '}' && charStack.size() && charStack.top() == '{')
			charStack.pop();
		else if (inputString[i] == ')' && charStack.size() && charStack.top() == '(')
			charStack.pop();
		else
			break;
	}
	if (!charStack.size() && i == inputString.size()) {
		cout << "Paranthesis are in order" << endl;
	} else {
		cout << "Paranthesis are not in order" << endl;
	}

	return 0;
}