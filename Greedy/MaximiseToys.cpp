//https://www.geeksforgeeks.org/maximise-the-number-of-toys-that-can-be-purchased-with-amount-k/
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int inputSize, amount, amountTillNow = 0, toysPurchased = 0;
	cout << "Enter the number of toys: ";
	cin >> inputSize;
	vector<int> toyPriceList(inputSize);
	cout << "Enter the price list: ";
	for (int i = 0; i < inputSize; i++)
		cin >> toyPriceList[i];
	cout << "Enter the amount you have: ";
	cin >> amount;
	sort(toyPriceList.begin(), toyPriceList.end());
	for (int i = 0; i< inputSize; i++) {
		amountTillNow += toyPriceList[i];
		if (amountTillNow <= amount)
			toysPurchased++;
	}
	cout << "Number of toys that can be purchased: " << toysPurchased << endl;
	return 0;
}