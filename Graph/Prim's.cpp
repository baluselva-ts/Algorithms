#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct Edge {
	int weight;
	int source;
	int destination;
};

struct CompareWeight {
	bool operator() (Edge const &E1, Edge const &E2) {
		return E1.weight > E2.weight;
	}
};

void getEdges(int numberOfEdges, map< int, vector<Edge> > &adjacencyList) {
	cout << "Enter source, destination (0 indexed) and weight of edges:" << endl;
	for (int i = 0, source, dest, weight; i < numberOfEdges; i++) {
		cin >> source >> dest >> weight;
		struct Edge e = {weight, source, dest};
		adjacencyList[source].push_back(e);
		adjacencyList[dest].push_back(e);
	}
}

void addEdgesToQueue(priority_queue<Edge, vector<Edge>, CompareWeight> &minimumEdge, map< int, vector<Edge> > adjacencyList, vector<int> &isVisited, int i) {
	if (adjacencyList.find(i) != adjacencyList.end()) {
		for (auto edge: adjacencyList[i]) {
			if (!isVisited[edge.source] || !isVisited[edge.destination])
				minimumEdge.push(edge);
		}
	}
}

int main() {
	map< int, vector<Edge> > adjacencyList;
	priority_queue<Edge, vector<Edge>, CompareWeight> minimumEdge;
	unordered_set<int> spanningTree;

	int numberOfVertices = 0, numberOfEdges = 0, pathDistance = 0;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of Edges: ";
	cin >> numberOfEdges;
	
	vector<int> isVisited(numberOfVertices);

	getEdges(numberOfEdges, adjacencyList);
	
	addEdgesToQueue(minimumEdge, adjacencyList, isVisited, 0);
	while (minimumEdge.size()) {
		Edge edgeToAdd = minimumEdge.top();
		minimumEdge.pop();
		if (!isVisited[edgeToAdd.source] || !isVisited[edgeToAdd.destination]) {
			if (pathDistance == 0)
				cout << edgeToAdd.source << "->" << edgeToAdd.destination;
			else
				cout << ", " << edgeToAdd.source << "->" << edgeToAdd.destination;
			if (!isVisited[edgeToAdd.source]) {
				isVisited[edgeToAdd.source] = 1;
				addEdgesToQueue(minimumEdge, adjacencyList, isVisited, edgeToAdd.source);
			}
			if (!isVisited[edgeToAdd.destination]) {
				isVisited[edgeToAdd.destination] = 1;
				addEdgesToQueue(minimumEdge, adjacencyList, isVisited, edgeToAdd.destination);
			}
			pathDistance += edgeToAdd.weight;
		}
	}
	cout << endl;
	cout << "Distance covered by the above spanning tree: " << pathDistance << endl;
	// for (int i = 0; i < numberOfVertices; i++) {
	// 	cout << i << " -> ";
	// 	if (adjacencyList.find(i) != adjacencyList.end())
	// 		for (auto adjacentVertex: adjacencyList[i])
	// 			cout << (adjacentVertex.weight) << " ";
	// 	cout << endl;
	// }

	return 0;
}