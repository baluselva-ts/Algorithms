//https://practice.geeksforgeeks.org/problems/rotten-oranges/0

#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void rotNearByOranges(vector< vector<int> > &inputArray, 
						pair<int, int> front, 
						queue< pair<int, int> > &rottenOranges,
						int rows,
						int cols) {
	int i = front.first;
	int j = front.second;

	if (j > 0 && inputArray[i][j - 1] == 1) {
		// cout << "Left" << endl;
		inputArray[i][j - 1] = 2;
		rottenOranges.push(make_pair(i, j - 1));
	}
	if (j < cols - 1 && inputArray[i][j + 1] == 1) {
		// cout << "Right" << endl;
		inputArray[i][j + 1] = 2;
		rottenOranges.push(make_pair(i, j + 1));
	}
	if (i > 0 && inputArray[i - 1][j] == 1) {
		// cout << "Up" << endl;
		inputArray[i - 1][j] = 2;
		rottenOranges.push(make_pair(i - 1, j));
	}
	if (i < rows - 1 && inputArray[i + 1][j] == 1) {
		// cout << "Down" << endl;
		inputArray[i + 1][j] = 2;
		rottenOranges.push(make_pair(i + 1, j));
	}
}

bool anyFreshOrangeAvaialble(vector< vector<int> > inputArray, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0 ; j < cols; j++) {
			if (inputArray[i][j] == 1)
				return true;
		}
	}
	return false;
}

int getMinimumTimeToRot(vector< vector<int> > inputArray, int rows, int cols) {
	pair<int, int> DELIMITER (-1, -1);
	queue< pair<int, int> > rottenOranges;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (inputArray[i][j] == 2) {
				rottenOranges.push(make_pair(i, j));
			}
		}
	}
	rottenOranges.push(DELIMITER);

	int time = 0;

	while (rottenOranges.size() > 1) {
		while(rottenOranges.front() != DELIMITER) {
			// cout << rottenOranges.front().first << ", " << rottenOranges.front().second << endl;
			rotNearByOranges(inputArray, rottenOranges.front(), rottenOranges, rows, cols);
			rottenOranges.pop();
		}
		// cout << endl;
		rottenOranges.pop();
		rottenOranges.push(DELIMITER);
		time += (rottenOranges.size() > 1);
	}
	// while (rottenOranges.size()) {
	// 	cout << rottenOranges.front().first << ", " << rottenOranges.front().second << endl;
	// 	rottenOranges.pop();
	// }
	return anyFreshOrangeAvaialble(inputArray, rows, cols) ? -1 : time;
}

int main() {
	int rows = 0, cols = 0;
	cout << "Enter number of rows and columns:";
	cin >> rows >> cols;

	vector< vector<int> > inputArray(rows, vector<int> (cols));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> inputArray[i][j];
		}
	}
	cout << endl;
	cout << getMinimumTimeToRot(inputArray, rows, cols) << endl;

	// for (int i = 0; i < rows; i++) {
	// 	for (int j = 0; j < cols; j++) {
	// 		cout << inputArray[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}