//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
#include <iostream>
#include <vector>
#include <string>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int getLCSRecursive(string firstString, string secondString, int firstPointer, int secondPointer) {
	if (firstPointer >= firstString.length() || secondPointer >= secondString.length())
		return 0;
	if (firstString[firstPointer] == secondString[secondPointer])
		return 1 + getLCSRecursive(firstString, secondString, firstPointer + 1, secondPointer + 1);
	else
		return MAX(
			getLCSRecursive(firstString, secondString, firstPointer, secondPointer + 1),
			getLCSRecursive(firstString, secondString, firstPointer + 1, secondPointer)
		);
}


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

int main() {
	string firstString, secondString;
	cout << "Enter the input strings: ";
	cin >> firstString >> secondString;

	cout << "Length of longest common subsequence: " << getLCSRecursive(firstString, secondString, 0, 0) << endl;

	getLCSIterative(firstString, secondString);



	return 0;
}