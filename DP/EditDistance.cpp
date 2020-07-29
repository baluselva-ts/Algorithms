//https://www.geeksforgeeks.org/edit-distance-dp-5/
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

void print2DVector(vector < vector <int> > table) {
	for (auto row: table) {
		for (auto element: row)
			cout << element << " ";
		cout << endl;
	}
	cout << endl;
}

int getEditDistance(string firstString, string secondString) {
	int lengthA = firstString.length(), lengthB = secondString.length();
	vector < vector <int> > table(lengthA + 1, vector<int>(lengthB + 1));

	for (int i = 0; i <= lengthA; i++) {
		for (int j = 0; j <= lengthB; j++) {
			if (i == 0)
				table[i][j] = j;
			else if (j == 0)
				table[i][j] = i;
			else if (firstString[i - 1] == secondString[j - 1])
				table[i][j] = table[i - 1][j - 1];
			else
				table[i][j] = 1 + MIN(table[i][j - 1], MIN(table[i - 1][j - 1], table[i - 1][j]));
		}
	}
	return table[lengthA][lengthB];
}

int main() {
	string firstString, secondString;
	cout << "Enter first and second string: " << endl;
	cin >> firstString >> secondString;
	cout << "Edit distance between '" 
			<< firstString 
			<< "' and '" 
			<< secondString 
			<< "' is: " 
			<< getEditDistance(firstString, secondString) 
			<< endl;
	return 0;
}