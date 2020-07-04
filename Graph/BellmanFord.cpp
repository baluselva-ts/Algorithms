#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct Edge {
	int weight;
	int source;
	int destination;

	Edge (int s, int d, int w) : weight(w), source(s), destination(d) {}

	bool operator < (const Edge &edge) const {
		if (source < edge.source)
			return true;
		else if (source == edge.source && destination < edge.destination)
			return true;
		return false;
	}

	bool operator > (const Edge &edge) const {
		if (source > edge.source)
			return true;
		else if (source == edge.source && destination > edge.destination)
			return true;
		return false;
	}

	void print() {
		cout << source << " -> " << destination << " : " << weight << endl;
	}
};

void printVector(vector<int> array) {
	for (auto number: array) {
		cout << number << " ";
	}
	cout << endl;
}

void getEdges(int numberOfEdges, vector<Edge> &edges) {
	cout << "Enter source, destination (0 indexed) and weight of edges:" << endl;
	for (int i = 0, source, dest, weight; i < numberOfEdges; i++) {
		cin >> source >> dest >> weight;
		edges.push_back(Edge(source, dest, weight));
	}
}

void relaxEdges(vector<Edge> edges, vector<int> &minDistanceFromSource, bool &relaxed) {
	for (auto edge: edges) {
		int updatedMinDistance = MIN (minDistanceFromSource[edge.destination], minDistanceFromSource[edge.source] + edge.weight);
		if (minDistanceFromSource[edge.destination] != updatedMinDistance)
			relaxed = true;
		minDistanceFromSource[edge.destination] = updatedMinDistance;
	}
}

void printDistanceFromSource(vector<int> minDistanceFromSource, int source) {
	for (int i = 0; i < minDistanceFromSource.size(); i++)
		if (i != source)
			cout << source << " -> " << i << ": " << minDistanceFromSource[i] << endl;
}

int main() {
	int numberOfVertices = 0, numberOfEdges = 0, source = 0;
	cout << "Enter number of vertices: ";
	cin >> numberOfVertices;
	cout << "Enter number of Edges: ";
	cin >> numberOfEdges;

	vector<Edge> edges;
	getEdges(numberOfEdges, edges);
	sort(edges.begin(), edges.end());

	vector<int> minDistanceFromSource(numberOfVertices, INT_MAX);
	minDistanceFromSource[source] = 0;
	bool relaxed = false;

	for (int i = 0; i < numberOfVertices - 1; i++)
		relaxEdges(edges, minDistanceFromSource, relaxed);

	relaxed = false;
	relaxEdges(edges, minDistanceFromSource, relaxed);

	if(relaxed)
		cout << "Encountered a negative weight cycle. Can't run Bellman Ford algorithm" << endl;
	else
		printDistanceFromSource(minDistanceFromSource, source);
	return 0;
}