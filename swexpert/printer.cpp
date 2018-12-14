#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int siz = 0;
	int loc = 0;
	deque<int> deq;
	deque<int> idx;

	for (int i = 0; i < priorities.size(); i++)
	{
		deq.push_back(priorities[i]);
	}
	for (int i = 0; i < priorities.size(); i++)
	{
		idx.push_back(i);
	}
	int count = 1;

	while (1) {
		int max = 0;
		int loc = 0;
		for (int i = 0; i < deq.size(); i++)
		{
			if (max < deq[i])
			{
				loc = i;
				max = deq[i];
			}
		}

		for (int i = 0; i < loc; i++)
		{
			int tmp1 = deq.front();
			int tmp2 = idx.front();
			deq.pop_front();
			deq.push_back(tmp1);
			idx.pop_front();
			idx.push_back(tmp2);
		}

		if (idx.front() != location) {
			deq.pop_front();
			idx.pop_front();
			count++;
		}
		else
		{
			answer = count++;
			return answer;
		}
	}
}

int main() {

	vector<int> pri = {2,2,2,1,3,4};
	int location = 3;
	cout << solution(pri, location) << endl;
	return 0;
}