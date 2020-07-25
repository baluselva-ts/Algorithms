//https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int offer = 0, typesOfCandy = 0, toBuy, minAmount = 0, maxAmount = 0;
	cout << "Enter the types of candy: ";
	cin >> typesOfCandy;
	cout << "Enter the offer candies (Buy 1 get ?): ";
	cin >> offer;

	vector<int> costOfCandy(typesOfCandy);
	for (int i = 0; i < typesOfCandy; i++)
		cin >> costOfCandy[i];
	sort(costOfCandy.begin(), costOfCandy.end());
	toBuy = (typesOfCandy % (offer + 1) == 0) ? (typesOfCandy / offer) - 1 : typesOfCandy / offer;
	for (int i = 0; i < toBuy; i++) {
		minAmount += costOfCandy[i];
		maxAmount += costOfCandy[typesOfCandy - i - 1];
	}
	cout << "Minimum amount to buy all type of candies: " << minAmount << endl;
	cout << "Maximum amount to buy all type of candies: " << maxAmount << endl;
	return 0;
}