//https://www.geeksforgeeks.org/find-array-strings-can-chained-form-circle-set-2/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

// this should either only one strongly connected component 
// or in/out degree of each vertex shuld be same and normal dfs should cover all the vertices

void tranposeOfMatrix(vector< vector<int> > matrixOne, vector< vector<int> > &matrixTwo) {
	for (int i = 0; i < matrixOne.size(); i++)
		for (int j = 0; j < matrixOne[i].size(); j++)
			matrixTwo[i][j] = matrixOne[j][i];
}

int getNumberOfVertices(vector<string> inputStrings, map<char, int> &vertexNumberMap) {
	int index = 0;
	for (int i = 0 ; i < inputStrings.size(); i++) {
		string thisString = inputStrings[i];
		int thisStringLength = thisString.length();
		if (vertexNumberMap.find(thisString[0]) == vertexNumberMap.end())
			vertexNumberMap[thisString[0]] = index++;
		if (vertexNumberMap.find(thisString[thisStringLength - 1]) == vertexNumberMap.end())
			vertexNumberMap[thisString[thisStringLength - 1]] = index++;
	}
	return vertexNumberMap.size();
}

void dfs(vector< vector<int> > adjacencyMatrix, int numberOfVertices, int vertex, vector<int> &vertexOrderedbyOutTime, vector<int> &isVisited) {
	if (!isVisited[vertex]) {
		isVisited[vertex] = 1;
		for (int i = 0; i < numberOfVertices; i++) {
			if (adjacencyMatrix[vertex][i] == 1 && !isVisited[i])
				dfs(adjacencyMatrix, numberOfVertices, i, vertexOrderedbyOutTime, isVisited);
		}
		vertexOrderedbyOutTime.push_back(vertex);
	}
}

void dfsReverse(vector< vector<int> > adjacencyMatrix, int numberOfVertices, int vertex, vector<int> &isVisited) {
	if (!isVisited[vertex]) {
		isVisited[vertex] = 1;
		for (int i = 0; i < numberOfVertices; i++) {
			if (adjacencyMatrix[vertex][i] == 1 && !isVisited[i])
				dfsReverse(adjacencyMatrix, numberOfVertices, i, isVisited);
		}
	}
}

void buildAdjacencyMatrix(vector<string> inputStrings, map<char, int> vertexNumberMap, vector< vector<int> > &adjacencyMatrix ) {
	for (int i = 0 ; i < inputStrings.size(); i++) {
		int firstCharIndex = vertexNumberMap[inputStrings[i][0]];
		int lastCharIndex = vertexNumberMap[inputStrings[i][inputStrings[i].size() - 1]];
		adjacencyMatrix[firstCharIndex][lastCharIndex] = 1;
	}
}

int main() {
	int numberOfStrings = 0, numberOfVertices = 0;
	map<char, int> vertexNumberMap;

	cout << "Enter number of strings: ";
	cin >> numberOfStrings;

	vector<string> inputStrings(numberOfStrings);
	for (int i = 0; i < numberOfStrings; i++)
		cin >> inputStrings[i];	
	numberOfVertices = getNumberOfVertices(inputStrings, vertexNumberMap);
	vector<int> isVisited(numberOfVertices, 0);
	vector<int> vertexOrderedbyOutTime;

	vector< vector<int > >adjacencyMatrix(numberOfVertices, vector<int>(numberOfVertices));
	buildAdjacencyMatrix(inputStrings, vertexNumberMap, adjacencyMatrix);

	int source = 0;
	for (int i = 0; i < numberOfVertices; i++) {
		if (!isVisited[i])
			dfs(adjacencyMatrix, numberOfVertices, i, vertexOrderedbyOutTime, isVisited);
	}
	fill(isVisited.begin(), isVisited.end(), 0);
	
	vector< vector<int> > adjacencyMatrixInverted(numberOfVertices, vector<int>(numberOfVertices));
	tranposeOfMatrix(adjacencyMatrix, adjacencyMatrixInverted);
	int stronglyConnectedComponentIndex = 0;
	for (int i = vertexOrderedbyOutTime.size() - 1; i >= 0; i--) {
		if(!isVisited[vertexOrderedbyOutTime[i]]) {
			stronglyConnectedComponentIndex = i;
			dfsReverse(adjacencyMatrixInverted, numberOfVertices, vertexOrderedbyOutTime[i], isVisited);
		}
	}

	if (stronglyConnectedComponentIndex == vertexOrderedbyOutTime.size() - 1)
		cout << "Can be Chained" << endl;
	else
		cout << "Can't be Chained" << endl;

	return 0;
}