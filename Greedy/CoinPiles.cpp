//https://practice.geeksforgeeks.org/problems/coin-piles/0
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int getMinCoinsRemoved(vector<int> coinPiles, int maxDifference) {
	int smallestPile = INT_MAX, coinsRemoved = 0;
	for (int i = 0; i < coinPiles.size(); i++)
		smallestPile = MIN(smallestPile, coinPiles[i]);
	for (int i = 0; i < coinPiles.size(); i++)
		if (coinPiles[i] > smallestPile && abs(coinPiles[i] - smallestPile) > maxDifference)
			coinsRemoved += (abs(coinPiles[i] - smallestPile) - maxDifference);
	return coinsRemoved;
}

int main() {
	int inputSize, maxDifference;
	cout << "Enter the input size: ";
	cin >> inputSize;
	vector<int> coinPiles(inputSize);
	cout << "Enter the pile sizes: ";
	for (int i = 0; i < inputSize; i++)
		cin >> coinPiles[i];
	cout << "Enter the max difference: ";
	cin >> maxDifference;
	cout << "Minimum coins to be removed: " << getMinCoinsRemoved(coinPiles, maxDifference) << endl;
	return 0;
}