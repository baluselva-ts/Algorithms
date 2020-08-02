//https://www.geeksforgeeks.org/maximize-the-number-of-segments-of-length-p-q-and-r/
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int findMaxSegmentsRecursive(int length, int p, int q, int r, vector<int> &maxSegments) {
	if (maxSegments[length] != -1)
		return maxSegments[length];
	else if (length == 0)
		return 0;
	else {
		int maxA = -1, maxB = -1, maxC = -1;
		if (length >= p )
			maxA = findMaxSegmentsRecursive(length - p, p, q, r, maxSegments);
		if (length >= q)
			maxB = findMaxSegmentsRecursive(length - q, p, q, r, maxSegments);
		if (length >= r)
			maxC = findMaxSegmentsRecursive(length - r, p, q, r, maxSegments);
		int maxValue = MAX(maxA, MAX(maxB, maxC));
		if (maxValue != -1)
			maxValue++;
		maxSegments[length] = maxValue;
		return maxSegments[length];
	}
}

int findMaxSegmentsIterative(int length, int p, int q, int r, vector<int> &maxSegments) {
	maxSegments[0] = 0;
	for (int i = 0; i < length; i++) {
		if (maxSegments[i] == -1) {
			if (i + p <= length)
				maxSegments[i + p] = MAX(maxSegments[i + p], maxSegments[i] + 1);
			if (i + q <= length)
				maxSegments[i + q] = MAX(maxSegments[i + q], maxSegments[i] + 1);
			if (i + r <= length)
				maxSegments[i + r] = MAX(maxSegments[i + r], maxSegments[i] + 1);
		}
	}
	return maxSegments[length];
}

int main() {
	int p, q, r, lengthOfRod;
	cout << "Enter values for p, q and r: ";
	cin >> p >> q >> r;
	cout << "Enter the length of rod: ";
	cin >> lengthOfRod;
	vector<int> maxSegments(lengthOfRod + 1, -1);

	int answer = findMaxSegmentsRecursive(lengthOfRod, p, q, r, maxSegments);
	cout << "The maximum segments we can get from rod of length " << lengthOfRod << " is: " << answer << endl;

	answer = findMaxSegmentsIterative(lengthOfRod, p, q, r, maxSegments);
	cout << "The maximum segments we can get from rod of length " << lengthOfRod << " is: " << answer << endl;

	return 0;
}