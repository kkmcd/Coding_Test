#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size()-1; i++)
	{
		int sec = 0;
		for (int j = i+1; j < prices.size(); j++)
		{
			
		}
	}
	return answer;
}

int main() {

	vector<int> val;
	vector<int> prices = { 498,501,470,489 };
	val = solution(prices);
	for (int i = 0; i < val.size(); i++)
	{
		cout << val[i] << " ";
	}

	return 0;
}