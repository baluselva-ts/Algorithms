//https://www.geeksforgeeks.org/program-for-least-recently-used-lru-page-replacement-algorithm/
#include <iostream>
#include <vector>
#include <map>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

struct Queue {
	vector<int> queue;
	int capacity;
	map<int, int> availableInCache;

	void push(int element) {
		queue.push_back(element);
		availableInCache[element] = 1;
	}

	void pop() {
		availableInCache.erase(queue[0]);
		queue.erase(queue.begin(), queue.begin() + 1);
	}

	void swap(int i, int j) {
		int temp = queue[i];
		queue[i] = queue[j];
		queue[j] = temp;
	}

	void reInsertPage(int element) {
		for (int i = 1; i < queue.size(); i++)
			if (queue[i - 1] == element)
				swap(i, i - 1);
	}

	bool hasPage(int element) {
		return availableInCache.find(element) != availableInCache.end();
	}

	int size() {
		return queue.size();
	}
};

int main() {
	Queue cache;
	int numberOfPages, capacity, pageFaults = 0;
	cout << "Enter number of pages and capacity: ";
	cin >> numberOfPages >> cache.capacity;

	vector<int> pages(numberOfPages);
	for (int i = 0; i < numberOfPages; i++) {
		cin >> pages[i];
		if (cache.hasPage(pages[i]))
			cache.reInsertPage(pages[i]);
		else {
			pageFaults++;
			if (cache.size() >= cache.capacity)
				cache.pop();
			cache.push(pages[i]);
		}
	}

	cout << "Page Faults: " << pageFaults << endl;
	return 0;
}