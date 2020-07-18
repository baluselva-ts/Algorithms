//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
//without extra space - https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/?ref=rp
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int getTableValue(vector <vector<int> > table, int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	return table[i][j];
}

//dynamic
void printLongestPalindrome(string inputString) {
	int strLen = inputString.length();
	vector <vector<int> > table(strLen, vector<int>(strLen, 0));
	int maxLengthPalindrome = INT_MIN;
	int maxLengthPalindromeIndex = -1;

	for (int i = 0; i < strLen; i++)
		for(int j = strLen - 1, k = 0; j >= 0; j--, k++)
			if (inputString[i] == inputString[j]) {
				table[i][k] = getTableValue(table, i - 1, k - 1) + 1;
				if (table[i][k] > maxLengthPalindrome) {
					maxLengthPalindrome = table[i][k];
					maxLengthPalindromeIndex = i;
				}
	}
	int startIndex = maxLengthPalindromeIndex - maxLengthPalindrome + 1;
	cout << "Longest Palindrome length: " << maxLengthPalindrome << "\nStarting from index: " << startIndex << endl;
	cout << inputString.substr(startIndex, maxLengthPalindrome) << endl;
}

//recursion
int getPalindrome(string inputString, int start, int end, int length) {
	if (start > end)
		return length;
	if (start == end)
		return (length + 1);
	if (inputString[start] == inputString[end]) {
		length = getPalindrome(inputString, start + 1, end - 1, length + 2);
		return MAX(length, MAX(getPalindrome(inputString, start, end - 1, 0), getPalindrome(inputString, start + 1, end, 0)));
	}
	return MAX(getPalindrome(inputString, start, end - 1, 0), getPalindrome(inputString, start + 1, end, 0));
}

int main() {
	string inputString;
	int length = 0;
	cout << "Enter input string: ";
	cin >> inputString;

	printLongestPalindrome(inputString);
	cout << getPalindrome(inputString, 0, inputString.length() - 1, length) << endl;
	return 0;
}