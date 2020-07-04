#include <iostream>
#include <queue>
#include <map>
#include <stack>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

int getNextMinUnvisitedNode(vector<int> minDistance, vector<int> isVisited) {
	int nextMin = INT_MAX;
	int vertexWithMinDistance;

	for (int i = 0; i < minDistance.size(); i++) {
		if (!isVisited[i] && minDistance[i] < nextMin) {
			nextMin = minDistance[i];
			vertexWithMinDistance = i;
		}
	}
	return (nextMin != INT_MAX) ? vertexWithMinDistance : -1;
}

void printVector(vector<int> array) {
	for (auto number: array) {
		cout << number << " ";
	}
	cout << endl;
}

void printDistanceFromSource(vector<int> minDistanceFromSource, int source) {
	for (int i = 0; i < minDistanceFromSource.size(); i++)
		if (i != source)
			cout << source << " -> " << i << ": " << minDistanceFromSource[i] << endl;
}

int main() {
	int numberOfVertices;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;

	vector<int> isVisited(numberOfVertices);
	vector< vector<int> > adjacencyMatrix(numberOfVertices, vector<int>(numberOfVertices, INT_MAX));

	int numberOfEdges;
	cout << "Enter number of edges: ";
	cin >> numberOfEdges;

	cout << "Enter source, destination (0 indexed) and weight of edges:" << endl;
	for (int i = 0, source, dest, weight; i < numberOfEdges; i++) {
		cin >> source >> dest >> weight;
		adjacencyMatrix[source][dest] = weight;
	}
	vector<int> minDistance(numberOfVertices, INT_MAX);
	int source = 0;
	int distanceCovered = 0;
	int currentNode = source;
	minDistance[currentNode] = 0;
	for (int i = 0; i < numberOfVertices && !isVisited[currentNode]; i++) {
		isVisited[currentNode] = 1;
		for (int j = 0; j < numberOfVertices; j++)
			if (currentNode != j && !isVisited[j] && adjacencyMatrix[currentNode][j] != INT_MAX)
				minDistance[j] = MIN(minDistance[j], distanceCovered + adjacencyMatrix[currentNode][j]);
		currentNode = getNextMinUnvisitedNode(minDistance, isVisited);
		if (currentNode != -1) 
			distanceCovered = minDistance[currentNode];
	}
	printDistanceFromSource(minDistance, source);
	return 0;
}