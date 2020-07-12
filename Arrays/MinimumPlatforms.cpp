//https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int main() {
	int numberOfTrains = 0, numberOfPlatforms = 0, maxNumberOfPlatforms = INT_MIN;
	cout << "Enter number of trains: ";
	cin >> numberOfTrains;
	map<int, int> trainArrivalDep;

	cout << "Enter arrival and departure time: "; 
	for (int i = 0, arrival, departure; i < numberOfTrains; i++) {
		cin >> arrival >> departure;
		if (trainArrivalDep.find(arrival) != trainArrivalDep.end())
			trainArrivalDep[arrival]++;
		else
			trainArrivalDep[arrival] = 1;
		if (trainArrivalDep.find(departure) != trainArrivalDep.end())
			trainArrivalDep[departure]--;
		else
			trainArrivalDep[departure] = -1;
	}

	for (map<int, int>::iterator i = trainArrivalDep.begin(); i != trainArrivalDep.end(); i++) {
		numberOfPlatforms += i -> second;
		maxNumberOfPlatforms = MAX(maxNumberOfPlatforms, numberOfPlatforms);
	}

	cout << "Maximum number of platforms needed: " << maxNumberOfPlatforms << endl;
	return 0;
}