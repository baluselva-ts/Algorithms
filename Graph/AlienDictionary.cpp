//https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

void dfs(map<char, unordered_set<char> > adjacencyList, map<char, int> &isVisited, char source) {
	if (!isVisited[source]) {
		isVisited[source] = 1;
		if (adjacencyList.find(source) != adjacencyList.end()) {
			for (unordered_set<char> :: iterator itr = adjacencyList[source].begin(); itr != adjacencyList[source].end(); itr++) {
				dfs(adjacencyList, isVisited, *itr);
			}
		}
		cout << source << " ";
	}

}

int main() {
	int inputSize = 0;
	cout << "Enter number of strings: ";
	cin >> inputSize;
	vector<string> inputStrings(inputSize);
	map<char, int> isVisited;

	cout << "Enter input strings: ";
	for (int i = 0, index = 0; i < inputSize; i++) {
		cin >> inputStrings[i];
		for (int j = 0; j < inputStrings[i].length(); j++)
			isVisited[inputStrings[i][j]] = 0;
	}

	map<char, unordered_set<char> > adjacencyList;
	
	for (int i = 1; i < inputSize; i++) {
		string firstString = inputStrings[i - 1];
		string secondString = inputStrings[i];
		int j = 0;
		while (j < firstString.length() && j < secondString.length() && firstString[j] == secondString[j]) {
			j++;
		}
		adjacencyList[secondString[j]].insert(firstString[j]);
	}
	for (map<char, int> :: iterator itr = isVisited.begin(); itr != isVisited.end(); itr++)
		if (!isVisited[itr -> second])
			dfs(adjacencyList, isVisited, itr -> first);
	cout << endl;
}