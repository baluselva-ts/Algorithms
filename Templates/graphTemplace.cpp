#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void getEdges(map<int, vector<int> > &adjacencyMatrix, int numberOfEdges) {
	cout << "Enter source and destination vectex(0 indexed) of edges:" << endl;
	for (int i = 0; i < numberOfEdges; i++) {
		int source, destination;
		cin >> source >> destination;
		adjacencyMatrix[source].push_back(destination);
	}
}

void printAdjacencyMatrix(map<int, vector<int> >adjacencyMatrix, int numberOfVertices) {
	cout << "Adjacency Matrix:" << endl;
	for (int i = 0; i < numberOfVertices; i++) {
		cout << i << " -> ";
		if (adjacencyMatrix.find(i) != adjacencyMatrix.end()) {
			for (int j = 0; j < adjacencyMatrix[i].size(); j++) {
				cout << adjacencyMatrix[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int main() {
	map<int, vector<int> >adjacencyMatrix;
	int numberOfVertices = 0, numberOfEdges = 0;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of Edges: ";
	cin >> numberOfEdges;
	getEdges(adjacencyMatrix, numberOfEdges);
	printAdjacencyMatrix(adjacencyMatrix, numberOfVertices);

	return 0;
}