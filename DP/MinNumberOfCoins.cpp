//https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int denominationSize = 0, amount = 0;
	cout << "Enter number of denominations: ";
	cin >> denominationSize;
	cout << "Enter the amount: ";
	cin >> amount;

	vector<int> denominations(denominationSize);
	for (int i = 0; i < denominationSize; i++)
		cin >> denominations[i];

	vector<int> minCoins(amount + 1, INT_MAX);
	minCoins[0] = 0;

	for (int i = 1, j; i <= amount; i++) {
		j = 0;
		while (j < denominationSize && denominations[j] <= i) {
			if (minCoins[i - denominations[j]] != INT_MAX) {
				minCoins[i] = MIN(minCoins[i], minCoins[i - denominations[j]] + 1);
			}
			j++;
		}
	}
	cout << "Minimum coins to get " << amount << " is: " << minCoins[amount] << endl;
	return 0;
}