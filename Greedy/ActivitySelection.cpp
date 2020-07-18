//https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
#include <iostream>
#include <vector>
using namespace std;

struct Activity {
	int startTime;
	int endTime;

	Activity(int s, int e) : startTime(s), endTime(e) {}

	bool operator < (const Activity &activity) const {
		if (endTime < activity.endTime)
			return true;
		else if (endTime == activity.endTime && startTime > activity.startTime)
			return true;
		return false;
	}

	bool operator > (const Activity &activity) const {
		if (endTime > activity.endTime)
			return true;
		else if (endTime == activity.endTime && startTime < activity.startTime)
			return true;
		return false;
	}

	void printActivity() {
		cout << startTime << " -> " << endTime << endl;
	}
};

void printActivities(vector<Activity> activities) {
	for (auto element: activities)
		element.printActivity();
}

int main() {
	int inputSize = 0;
	cout << "Enter number of activities: ";
	cin >> inputSize;

	vector<Activity> activities;
	cout << "Enter start and end time for activities: ";
	for (int i = 0, start, end; i < inputSize; i++) {
		cin >> start >> end;
		activities.push_back(Activity(start, end));
	}

	// cout << "\nBefore Sorting: " << endl;
	// printActivities(activities);
	sort(activities.begin(), activities.end());
	// cout << "\nAfter Sorting: " << endl;
	// printActivities(activities);

	cout << "Activities we can select: " << endl;
	for (int i = 0, previousEndTime = INT_MIN; i < inputSize; i++) {
		if (activities[i].startTime >= previousEndTime) {
			activities[i].printActivity();
			previousEndTime = activities[i].endTime;
		}		
	}
	return 0;
}