#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	map<string, int> strmap;
	int save[1000];

	for (int i = 0; i < clothes.capacity(); i++)
	{
		if (strmap.end() == strmap.find(clothes[i][1])) {
			strmap.insert(make_pair(clothes[i][1], 1));
		}
		else {
			strmap[clothes[i][1]]++;
		}
	}
	int i = 0;

	for (auto elem : strmap)
	{
		save[i] = elem.second;
		//cout << save[i] << endl;
		i++;
	}

	int mul = 1;

	if (i != 1) {
		for (int p = 0; p < i; p++)
		{
			mul *= (save[p]+1);
		}
	}
	else
		mul = save[0]+1;
	answer = mul-1;
	return answer;
}

int main() {

	vector<vector<string>> str = { {"crow_mask", "face"},{"ddd", "face"},{"ccc", "face"} };
	cout << solution(str);

	return 0;
}