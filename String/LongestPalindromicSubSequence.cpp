//https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
#include <iostream>
#include <vector>
#include <string>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int getTableValue(vector< vector<int> > table, int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	return table[i][j];
}

void getLCSIterative(string firstString, string secondString) {
	vector< vector<int> > table(firstString.length(), vector<int>(secondString.length(), 0));
	for (int i = 0; i < firstString.length(); i++) {
		for (int j = 0; j < secondString.length(); j++) {
			if (firstString[i] == secondString[j])
				table[i][j] = MIN(MIN(getTableValue(table, i, j - 1), getTableValue(table, i - 1, j)), getTableValue(table, i - 1, j - 1)) + 1;
			else
				table[i][j] = MAX(MAX(getTableValue(table, i, j - 1), getTableValue(table, i - 1, j)), getTableValue(table, i - 1, j - 1));
		}
	}
	cout << "Length of longest common subsequence: " << table[firstString.length() - 1][secondString.length() - 1] << endl;
}

int main () {
	string firstString;
	cout << "Enter the input string: ";
	cin >> firstString;

	getLCSIterative(firstString, string(firstString.rbegin(), firstString.rend()));

	return 0;
}