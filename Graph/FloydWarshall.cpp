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
	cout << "Enter source, destination (0 indexed) and weight of edges:" << endl;
	for (int i = 0, source, dest, weight; i < numberOfEdges; i++) {
		cin >> source >> dest >> weight;
		adjacencyMatrix[source][dest] = weight;
	}
}

void print2DVector(vector< vector<int> > adjacencyMatrix, int numberOfVertices) {
	for (int i = 0; i < numberOfVertices; i++) {
		cout << i << " -> ";
		for (int j = 0; j < numberOfVertices; j++) {
			cout << adjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

vector< vector<int> > runFloydWarshallAlgorithm(vector< vector<int> > adjacencyMatrix, int numberOfVertices) {
	vector< vector<int> > allPairShortestPath = adjacencyMatrix;

	for (int i = 0 ; i < numberOfVertices; i++)
		for (int j = 0; j < numberOfVertices; j++)
			for (int k = 0; k < numberOfVertices; k++)
				if (j != k && allPairShortestPath[j][i] != INT_MAX && allPairShortestPath[i][k] != INT_MAX)
					allPairShortestPath[j][k] = MIN(allPairShortestPath[j][k], allPairShortestPath[j][i] + allPairShortestPath[i][k]);
	return allPairShortestPath;
}

int main() {
	int numberOfVertices = 0, numberOfEdges = 0;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of Edges: ";
	cin >> numberOfEdges;

	vector< vector<int> > adjacencyMatrix(numberOfVertices, vector<int>(numberOfVertices, INT_MAX));

	getEdges(adjacencyMatrix, numberOfEdges);
	for (int i = 0; i < numberOfVertices; i++)
		adjacencyMatrix[i][i] = 0;
	cout << "Input:" << endl;
	print2DVector(adjacencyMatrix, numberOfVertices);
	cout << endl;

	cout << "All Pair Shortest Path:" << endl;
	vector< vector<int> > allPairShortestPath = runFloydWarshallAlgorithm(adjacencyMatrix, numberOfVertices);
	print2DVector(allPairShortestPath, numberOfVertices);

	return 0;
}