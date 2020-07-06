//https://www.geeksforgeeks.org/find-number-of-islands/?ref=rp
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long
#define previousRow i - 1
#define sameRow i
#define nextRow i + 1
#define previousColumn j - 1
#define sameColumn j
#define nextColumn j + 1

using namespace std;

int get1DIndex(int i, int j, int rows) {
	return (i * rows) + j;
}

void getInputMatrix(vector< vector<int> > &inputMatrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> inputMatrix[i][j];
}

void runDFS(vector< vector<int> > &inputMatrix, vector<int> &isVisited, int i, int j, int rows, int cols) {
	if (inputMatrix[i][j] == 1 && !isVisited[get1DIndex(i, j, rows)]) {
		isVisited[get1DIndex(i, j, rows)] = 1;

		runDFS(inputMatrix, isVisited, MAX(previousRow, 0), MAX(previousColumn, 0), rows, cols);
		runDFS(inputMatrix, isVisited, MAX(previousRow, 0), sameColumn, rows, cols);
		runDFS(inputMatrix, isVisited, MAX(previousRow, 0), MIN(nextColumn, cols - 1), rows, cols);
		runDFS(inputMatrix, isVisited, sameRow, MAX(previousColumn, 0), rows, cols);
		runDFS(inputMatrix, isVisited, sameRow, MIN(nextColumn, cols - 1), rows, cols);
		runDFS(inputMatrix, isVisited, MIN(nextRow, rows - 1), MAX(previousColumn, 0), rows, cols);
		runDFS(inputMatrix, isVisited, MIN(nextRow, rows - 1), sameColumn, rows, cols);
		runDFS(inputMatrix, isVisited, MIN(nextRow, rows - 1), MIN(nextColumn, cols - 1), rows, cols);
	}
}

int main() {
	int rows = 0, cols = 0, numberOfIslands = 0;
	cout << "Enter number of rows an cols: ";
	cin >> rows >> cols;
	cout << endl;
	vector< vector<int> > inputMatrix(rows, vector<int>(cols));
	getInputMatrix(inputMatrix, rows, cols);
	vector<int> isVisited(rows * cols, 0);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (inputMatrix[i][j] == 1 && !isVisited[get1DIndex(i, j, rows)] && ++numberOfIslands)
				runDFS(inputMatrix, isVisited, i, j, rows, cols);
	cout << "Number of Islands: " << numberOfIslands << endl;
	return 0;
}