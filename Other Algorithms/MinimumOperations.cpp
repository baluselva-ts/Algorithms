//https://practice.geeksforgeeks.org/problems/find-optimum-operation/0
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, count = 0;
	cout << "Enter N value: ";
	cin >> n;

	while (n > 0) {
		if (n % 2 == 0 || n == 1)
			count++;
		else
			count += 2;
		n /= 2;
	}

	cout << "Minimum operations to reach 0: " << count << endl;
}