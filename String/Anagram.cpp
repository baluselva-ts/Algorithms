//https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
#include <iostream>
#include <map>

using namespace std;

bool isAnagram(string firstString, string secondString) {
	int length1 = firstString.length();
	int length2 = secondString.length();

	if (length1 == length2) {
		map<char, int> bucket;

		for (int i = 0; i < length1; i++) {
			if (bucket.find(firstString[i]) != bucket.end())
				bucket[firstString[i]]++;
			else
				bucket[firstString[i]] = 1;
			if (bucket.find(secondString[i]) != bucket.end())
				bucket[secondString[i]]--;
			else
				bucket[secondString[i]] = -1;
		}

		for (map<char, int>::iterator i = bucket.begin(); i != bucket.end(); i++){
			if (i -> second != 0)
				return false;
		}
		return true;
	}
	return false;
}

int main() {
	string firstString, secondString;
	cout << "Enter first and second string: ";
	cin >> firstString >> secondString;

	if (isAnagram(firstString, secondString))
		cout << "Strings are Anagram of each other" << endl;
	else
		cout << "Strings aren't Anagram of each other" << endl;

	return 0;
}