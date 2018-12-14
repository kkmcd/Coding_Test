#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int cur = 0;
	int max = 0;
	answer.push_back(0);
	for (int i = 1; i < heights.size(); i++)
	{
		if (heights[i - 1] > heights[i]) {
			if (max < heights[i - 1])
				max = heights[i - 1];
			answer.push_back(i);
			cur = i;
		}
		else
		{
			if (max < heights[i]) {
				max = heights[i];
				answer.push_back(0);
			}
			else {
				answer.push_back(cur);
			}
		}

	}
	return answer;
}