//Kosaraju's algorithm
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void getEdges(vector< vector<int> > &adjacencyMatrix, int numberOfEdges) {
	for(int i = 0, source, destination; i < numberOfEdges; i++) {
		cin >> source >> destination;
		adjacencyMatrix[source][destination] = 1;
	}
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

void dfsPrint(vector< vector<int> > adjacencyMatrix, int numberOfVertices, int vertex, vector<int> &isVisited) {
	if (!isVisited[vertex]) {
		isVisited[vertex] = 1;
		cout << vertex << " ";
		for (int i = 0; i < numberOfVertices; i++) {
			if (adjacencyMatrix[vertex][i] == 1 && !isVisited[i])
				dfsPrint(adjacencyMatrix, numberOfVertices, i, isVisited);
		}
	}
}

void print1DVector(vector<int> array) {
	for (auto number: array) {
		cout << number << " ";
	}
	cout << endl;
}

void tranposeOfMatrix(vector< vector<int> > matrixOne, vector< vector<int> > &matrixTwo) {
	for (int i = 0; i < matrixOne.size(); i++)
		for (int j = 0; j < matrixOne[i].size(); j++)
			matrixTwo[i][j] = matrixOne[j][i];
}

int main() {
	int numberOfVertices, numberOfEdges;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << endl;
	cout << "Enter number of Edges: ";
	cout << endl;
	cin >> numberOfEdges;
	vector< vector<int> > adjacencyMatrix(numberOfVertices, vector<int>(numberOfVertices, 0));
	getEdges(adjacencyMatrix, numberOfEdges);
	
	vector<int> isVisited(numberOfVertices, 0);
	vector<int> vertexOrderedbyOutTime;

	int source = 1;
	for (int i = 0; i < numberOfVertices; i++) {
		if (!isVisited[i])
			dfs(adjacencyMatrix, numberOfVertices, i, vertexOrderedbyOutTime, isVisited);
	}
	fill(isVisited.begin(), isVisited.end(), 0);

	vector< vector<int> > adjacencyMatrixInverted(numberOfVertices, vector<int>(numberOfVertices));
	tranposeOfMatrix(adjacencyMatrix, adjacencyMatrixInverted);

	for (int i = vertexOrderedbyOutTime.size() - 1; i >= 0; i--) {
		if(!isVisited[vertexOrderedbyOutTime[i]]) {
			dfsPrint(adjacencyMatrixInverted, numberOfVertices, vertexOrderedbyOutTime[i], isVisited);
			cout << endl;
		}
	}

	return 0;
}