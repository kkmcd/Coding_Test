#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int sum = brown + red;
	int tmp = 0;
	int min = 30000000;
	int x = 0;
	int y = 0;
	for (int i = 1; i <= sum; i++)
	{
		tmp = sum / i;
		if (tmp*i == sum)
		{
			if (abs(tmp - i) < min) {
				min = abs(tmp - i);
				x = tmp;
				y = i;
			}
		}
	}

	if (x > y) {
		answer.push_back(x);
		answer.push_back(y);
	}

	else
	{	
		answer.push_back(y);
		answer.push_back(x);
	}
	return answer;
}