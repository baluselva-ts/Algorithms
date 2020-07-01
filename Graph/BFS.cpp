//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
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

void traverseBreathFirst(map<int, vector<int> >adjacencyMatrix, int numberOfVertices) {
	vector<bool> isVisited(numberOfVertices);
	queue<int> traversedVertices;

	// for (int i = numberOfVertices - 1; i >= 0; i--) {
	for (int i = 0; i < numberOfVertices; i++) {
		if (!isVisited[i]) {
			traversedVertices.push(i);
			isVisited[traversedVertices.front()] = 1;

			while (traversedVertices.size()) {
				vector<int> adjacentVertices = adjacencyMatrix[traversedVertices.front()];
				// sort(adjacentVertices.begin(), adjacentVertices.end(), greater<int>());
				sort(adjacentVertices.begin(), adjacentVertices.end());
				for (auto vertex: adjacentVertices) {
					if (!isVisited[vertex]) {
						traversedVertices.push(vertex);
						isVisited[vertex] = 1;						
					}
				}
				cout << traversedVertices.front() << " ";
				traversedVertices.pop();
			}
		}
	}
	cout << endl;
}

int main() {
	map<int, vector<int> >adjacencyMatrix;
	int numberOfVertices = 0, numberOfEdges = 0;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of Edges: ";
	cin >> numberOfEdges;
	getEdges(adjacencyMatrix, numberOfEdges);
	
	cout << "BFS: ";
	traverseBreathFirst(adjacencyMatrix, numberOfVertices);

	return 0;
}