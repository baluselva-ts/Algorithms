#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int getWays(vector<int> ways, int i) {
	if (i < 0)
		return 0;
	return ways[i];
}

int getNumberOfWays(int distance, vector<int> steps, int possibleSteps) {
	vector<int> ways(distance + 1, 0);
	ways[0] = 1;
	for (int i = 1; i <= distance; i++)
		for (int j = 0; j < possibleSteps; j++)
			ways[i] += getWays(ways, i - steps[j]);
	return ways[distance];
}

int main() {
	int distance = 0, possibleSteps = 0;
	cout << "Enter the distance to cover: ";
	cin >> distance;
	cout << "Enter number of possible steps followed by the steps values: ";
	cin >> possibleSteps;
	vector<int> steps(possibleSteps);
	for (int i = 0; i < possibleSteps; i++)
		cin >> steps[i];
	cout << "Possible ways: " << getNumberOfWays(distance, steps, possibleSteps) << endl;
	return 0;
}