//https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/
#include <iostream>
#include <map>

using namespace std;

void printDistinctCharacters(string inputString) {
	map<char, int> bucket;

	for (int i = 0 ; i < inputString.length(); i++) {
		if (bucket.find(inputString[i]) == bucket.end()) {
			cout << inputString[i];
			bucket[inputString[i]] = 1;
		}
	}
	cout << endl;
}

int main() {
	string inputString;
	cout << "Enter input string: ";
	getline(cin, inputString);

	printDistinctCharacters(inputString);

	return 0;
}