//https://practice.geeksforgeeks.org/problems/max-length-chain/1
#include <iostream>
#include <vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

struct Activity {
	int startTime;
	int endTime;

	Activity(int s, int e) : startTime(s), endTime(e) {}

	bool operator < (const Activity &activity) const {
		if (endTime < activity.endTime)
			return true;
		else if (endTime == activity.endTime && startTime < activity.startTime)
			return true;
		return false;
	}

	bool operator > (const Activity &activity) const {
		if (endTime > activity.endTime)
			return true;
		else if (endTime == activity.endTime && startTime > activity.startTime)
			return true;
		return false;
	}

	void printActivity() {
		cout << startTime << " -> " << endTime << endl;
	}
};

int main() {
	int numberOfPairs = 0, maxLength = INT_MIN;
	cout << "Enter number of Pairs: ";
	cin >> numberOfPairs;

	vector<Activity> activities;
	vector<int> chainLength(numberOfPairs, 1);
	cout << "Enter start and end time for activities: ";
	for (int i = 0, start, end; i < numberOfPairs; i++) {
		cin >> start >> end;
		activities.push_back(Activity(start, end));
	}

	sort(activities.begin(), activities.end());

	for (int i = 0; i < numberOfPairs; i++) {
		for (int j = i + 1; j < numberOfPairs; j++) {
			if (activities[i].endTime <= activities[j].startTime)
				chainLength[j] = MAX(chainLength[j], chainLength[i] + 1);
			maxLength = MAX(maxLength, chainLength[j]);
		}
	}
	cout << "Max Chain Length: " << maxLength << endl;
	return 0;
}