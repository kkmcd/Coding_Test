#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	
	priority_queue<int> pq;
	int start = 0;
	while (stock < k)
	{
		for (int i = start; i < dates.size(); i++)
		{
			if (stock >= dates[i])
			{
				pq.push(supplies[i]);
			}
			else
			{
				start = i;
				break;
			}
		}

		answer += 1;
		stock += pq.top();
		pq.pop();
	}
	return answer;
}