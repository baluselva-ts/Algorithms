//https://www.geeksforgeeks.org/coin-change-dp-7/
#include <iostream>
#include <vector>
#define MIN2(a,b) (((a)<(b))?(a):(b))
#define MAX2(a,b) (((a)>(b))?(a):(b))
#define MIN3(a,b,c) (((a)<(b)&&(a)<(c))?(a):((b)<(a)&&(b)<(c))?(b):(c))
#define MAX3(a,b,c) (((a)>(b)&&(a)>(c))?(a):((b)>(a)&&(b)>(c))?(b):(c))
using namespace std;

void print1DVector(vector<int> array) {
	for (auto element: array)
			cout << element << " ";
	cout << endl;
}

void print2DVector(vector < vector <int> > table) {
	for (auto row: table)
		print1DVector(row);
	cout << endl;
}

int getCoinChange(vector<int> denominations, int denominationTypes, int amount) {
	vector< vector<int> > table(denominationTypes + 1, vector<int>(amount + 1));
	for (int i = 0; i <= denominationTypes; i++) {
		for (int j = 0; j <= amount; j++) {
			if (i == 0)
				table[i][j] = 0;
			else if (j == 0)
				table[i][j] = 1;
			else
				table[i][j] = table[i - 1][j] + ((j - denominations[i - 1]) >= 0 ? table[i][j - denominations[i - 1]] : 0);
		}
		// cout << i << " => " << endl;
		// print2DVector(table);
	}
	return table[denominationTypes][amount];
}

int main() {
	int denominationTypes, amount;
	cout << "Enter types of denominations and the amount: ";
	cin >> denominationTypes >> amount;

	vector<int> denominations(denominationTypes);
	cout << "Enter denominations: ";
	for (int i = 0; i < denominationTypes; i++)
		cin >> denominations[i];

	cout << "Number of ways we can get "
		 << amount
		 << ": "
		 << getCoinChange(denominations, denominationTypes, amount)
		 << endl;

	return 0;
}