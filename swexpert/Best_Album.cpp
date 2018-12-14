#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	map<int, tuple<string, int>> str_map;

	for (int i = 0; i < genres.capacity(); i++)
	{
		str_map[i] = make_tuple(genres[i], plays[i]);
	}

	

	return answer;
}