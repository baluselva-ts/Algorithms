//https://practice.geeksforgeeks.org/problems/circular-tour/1
#include <iostream>
#include <queue>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int findStartingPoint(queue<int> travel, int numberOfPumps) {
	int surplus = 0;
	int deficient = 0;
	int startingPoint = -1;
	for (int i = 0; i < numberOfPumps; i++) {
		if ((surplus + travel.front()) >= 0) {
			surplus += travel.front();
			travel.pop();
		} else {
			surplus = 0;
			startingPoint = i + 1;
			deficient += travel.front();
			travel.pop();
		}
	}
	if ((surplus + deficient) >= 0) {
		return startingPoint;
	}
	return -1;
}

int main() {
	int numberOfPumps = 0;
	cout << "Enter number of Pumps: ";
	cin >> numberOfPumps;
	queue<int> travel;
	cout << "Enter input values for Available Petrol and Distance to Next Pump for all " << numberOfPumps << " pumps" << endl;
	for (int i = 0; i < numberOfPumps; i++) {
		int petrolAvailable = 0;
		int distanceToNextPump = 0;
		cin >> petrolAvailable;
		cin >> distanceToNextPump;
		travel.push(petrolAvailable - distanceToNextPump);
	}
	cout << findStartingPoint(travel, numberOfPumps) << endl;
	return 0;
}