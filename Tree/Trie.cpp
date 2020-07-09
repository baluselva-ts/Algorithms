//https://www.geeksforgeeks.org/trie-memory-optimization-using-hash-map/
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <set>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

using namespace std;

struct Trie {
	map<char, struct Trie*> characters;
	bool isEndOfWord;
};

struct Trie* createNode() {
	struct Trie* trie = new Trie;
	trie -> isEndOfWord = false;
	return trie;
}

void insert(struct Trie* &root, const string &str) {
	if (!root) {
		root = createNode();
	}
	struct Trie *temp = root;
	for (int i = 0; i < str.length(); i++) {
		if (temp -> characters.find(str[i]) == temp -> characters.end()) {
			temp -> characters[str[i]] = createNode();}
		temp = temp -> characters[str[i]];
	}
	temp -> isEndOfWord = true;
}

void printWord(vector<char> word) {
	for (auto character: word) {
		cout << character;
	}
	cout << endl;
}

void printTrie(struct Trie *root, vector<char> wordVector) {
	if (!root)
		return;
	vector<char> word;
	for (map<char, struct Trie*>::iterator itr = root -> characters.begin(); itr != root -> characters.end(); itr++) {
		word = wordVector;
		word.push_back(itr -> first);
		if (!itr -> second -> isEndOfWord)
			printTrie(itr -> second, word);
		else {
			printWord(word);
			printTrie(itr -> second, word);
		}
	}
	word.clear();
}

void searchForWord(struct Trie *root, const string &str, const string &type) {
	vector<char> word;
	struct Trie *temp = root;
	int i = 0;
	for (; i < str.length(); i++) {
		if (temp -> characters.find(str[i]) != temp -> characters.end()) {
			word.push_back(str[i]);
			temp = temp -> characters[str[i]];
		} 			
		else
			break;
	}
	if (i != str.length() || (type == "EXACT" && !temp -> isEndOfWord))
		cout << "String not found" << endl;
	else {
		if (type == "LIKE") {
			if (temp -> isEndOfWord)
				cout << str << endl;
			printTrie(temp, word);
		} else
			cout << str << endl;
	}
}

int main() {
	struct Trie *root = NULL;
	insert(root, "apple");
	insert(root, "ball");
	insert(root, "balaji");
	insert(root, "bala");
	insert(root, "bala murugan");
	insert(root, "cat");
	insert(root, "com");
	insert(root, "commute");
	insert(root, "compute");
	insert(root, "computer");

	string searchWord;
	cout << "Enter a word or prefix of a word to search for: ";
	cin >> searchWord;

	searchForWord(root, searchWord, "LIKE");

	cout << "Enter a word to search for: ";
	cin >> searchWord;
	searchForWord(root, searchWord, "EXACT");
	return 0;
}