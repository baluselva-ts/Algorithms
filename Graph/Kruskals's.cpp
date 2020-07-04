#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct Vertex {
	int rank;
	int id;
	int parentId;
};

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

void getEdges(int numberOfEdges, priority_queue<Edge, vector<Edge>, CompareWeight> &minimumEdge) {
	cout << "Enter source, destination (0 indexed) and weight of edges:" << endl;
	for (int i = 0, source, dest, weight; i < numberOfEdges; i++) {
		cin >> source >> dest >> weight;
		struct Edge e = {weight, source, dest};
		minimumEdge.push(e);
	}
}

int getParent(int vertexId, map<int, Vertex> &vertices) {
	if (vertices[vertexId].id != vertices[vertexId].parentId) {
		return getParent(vertices[vertexId].parentId, vertices);
	}
	return vertexId;
}

void Union(int vertexIdA, int vertexIdB, map<int, Vertex> &vertices) {
	int parentA = getParent(vertexIdA, vertices);
	int parentB = getParent(vertexIdB, vertices);

	if (parentA == parentB)
		return;

	if (vertices[parentA].rank < vertices[parentB].rank) {
		vertices[parentA].parentId = vertices[parentB].parentId;
	} else if (vertices[parentB].rank < vertices[parentA].rank) {
		vertices[parentB].parentId = vertices[parentA].parentId;
	} else {
		vertices[parentB].parentId = MAX(vertices[parentA].parentId, vertices[parentB].parentId);
		vertices[parentA].parentId = MAX(vertices[parentA].parentId, vertices[parentB].parentId);
		if (parentA == vertices[parentA].parentId)
			vertices[parentA].rank++;
		else
			vertices[parentB].rank++;
	}
}

int main() {
	map<int, Vertex> vertices;
	priority_queue<Edge, vector<Edge>, CompareWeight> minimumEdge;
	unordered_set<int> spanningTree;

	int numberOfVertices = 0, numberOfEdges = 0, pathDistance = 0;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of Edges: ";
	cin >> numberOfEdges;
	
	for (int i = 0; i < numberOfVertices; i++) {
		Vertex vertex = {0, i, i};
		vertices[i] = vertex;
	}

	vector<int> isVisited(numberOfVertices);

	getEdges(numberOfEdges, minimumEdge);

	while (minimumEdge.size()) {
		Edge top = minimumEdge.top();
		minimumEdge.pop();
		if (getParent(top.source, vertices) != getParent(top.destination, vertices)) {
			if (pathDistance == 0)
				cout << top.source << "->" << top.destination;
			else
				cout << ", " << top.source << "->" << top.destination;
			isVisited[top.source] = 1;
			isVisited[top.destination] = 1;

			Union(top.source, top.destination, vertices);
			pathDistance += top.weight;
		}
	}
	cout << endl;
	cout << "Distance covered by the above spanning tree: " << pathDistance << endl;
	return 0;
}