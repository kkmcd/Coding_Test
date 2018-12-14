#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool comp(const string &a, const string &b)
{
	if (a < b)
		return true;
	return false;
}

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	sort(participant.begin(), participant.end(), comp);
	sort(completion.begin(), completion.end(),comp);
	//for (int i = 0; i < participant.capacity(); i++) // 벡터에 값을 넣거나 확인할 때에는 capacity!
	//{
	//	cout << participant.back() << endl;
	//	participant.pop_back();
	//}

	//cout << endl << endl;

	//for (int i = 0; i < completion.capacity(); i++)
	//{
	//	cout << completion.back() << endl;
	//	completion.pop_back();
	//}
	while(!participant.empty())
	if (completion.back() == participant.back())
	{
		participant.pop_back();
		completion.pop_back();
	}
	else
	{
		answer = participant.back();
		participant.pop_back();
		return answer;
	}
}

int main() {

	vector<string> part = { "mislav","stanko","mislav","ana"};
	vector<string> comp = { "stanko","mislav","ana" };

	//cout << solution(part, comp) << endl;

	map<string, int> strmap;
	strmap = { {"a",1}, {"b",2},{"c",3} };
	return 0;
}