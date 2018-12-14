#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<vector<int>> commands;
vector<int> tmp;
string val;

int i = 0, j = 0, k = 0;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int p = 0; p < commands.size(); p++)
	{
		i = commands[p][0];
		j = commands[p][1];
		k = commands[p][2];
		for (int a = i - 1; a <= j - 1; a++) {
			tmp.push_back(arr[a]);
			//cout << tmp.back();
		}

		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[k - 1]);
		tmp.clear();
	}

	return answer;
}

int main() {

	cin >> val;
	for (int a = 0; a < val.length(); a++)
	{
		arr.push_back(val[a] - '0');
	}

	cin >> val;
	int n = 0;
	for (int a = 0; a < (val.length() / 3); a++)
	{
		for (int b = 0; b < 3; b++)
		{
			tmp.push_back(val[n] - '0');
			n++;
		}
		commands.push_back(tmp);
		tmp.clear();
	}

	solution(arr, commands);
	//for (int a = 0; a < (val.length() / 3); a++)
	//{
	//	for (int b = 0; b < 3; b++)
	//	{
	//		cout << commands[a][b] << endl;
	//	}
	//}

	return 0;
}