//https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int getTableValue(vector< vector<int> > table, int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	return table[i][j];
}

int getLCSLength(string firstString, string secondString) {
	vector< vector<int> > table(firstString.length(), vector<int>(secondString.length(), 0));
	for (int i = 0; i < firstString.length(); i++) {
		for (int j = 0; j < secondString.length(); j++) {
			if (firstString[i] == secondString[j])
				table[i][j] = MIN(MIN(getTableValue(table, i, j - 1), getTableValue(table, i - 1, j)), getTableValue(table, i - 1, j - 1)) + 1;
			else
				table[i][j] = MAX(MAX(getTableValue(table, i, j - 1), getTableValue(table, i - 1, j)), getTableValue(table, i - 1, j - 1));
		}
	}
	return table[firstString.length() - 1][secondString.length() - 1];
}

int main() {
	string inputString;
	int length = 0;
	cout << "Enter input string: ";
	cin >> inputString;
	cout << "Minimum Insert to make the string palindrome: " << inputString.length() - getLCSLength(inputString, string(inputString.rbegin(), inputString.rend())) << endl;
	return 0;
}