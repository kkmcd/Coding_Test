#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	vector<char> vec;

	for (int i = 0; i < arrangement.length(); i++)
	{
		if (arrangement[i] == '(') vec.push_back(arrangement[i]);
		else
		{
			vec.pop_back();
			if (arrangement[i - 1] == '(')
				answer += vec.size();
			else
				answer++;
		}
	}

	return answer;
}

int main() {

	string input = "()(((()())(())()))(())";
	string input1 = "(((()(()()))(())()))(()())";

	cout << solution(input);

	return 0;
}