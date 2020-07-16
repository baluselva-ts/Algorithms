//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
//without extra space - https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/?ref=rp
#include <iostream>
#include <vector>

using namespace std;

int getTableValue(vector <vector<int> > table, int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	return table[i][j];
}

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

int main() {
	string inputString;
	cout << "Enter input string: ";
	cin >> inputString;

	printLongestPalindrome(inputString);

	return 0;
}