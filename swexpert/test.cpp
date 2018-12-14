#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string solution(vector<string> part, vector<string> comp)
{
	map<string, int> mp;
	string answer = "";

	for (auto elem : comp)
	{
		if (mp.end() == mp.find(elem))
		{
			mp.insert(make_pair(elem, 1));
		}
		else
		{
			mp[elem]++;
		}
	}

	for (auto elem : part)
	{
		if (mp.end() == mp.find(elem))
		{
			answer = elem;
			return answer;
		}
		else {
			mp[elem]--;
			if (mp[elem] < 0) {
				answer = elem;
				return answer;
			}
		}
	}

	return answer;
}