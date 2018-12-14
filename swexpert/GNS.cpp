#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {

	int all;
	string idx;
	int testcase;
	string val[10001];
	vector<string> save;
	string order[10] = { "ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN" };
	cin >> all;

	for (int k = 0; k < all; k++) {
		cin >> idx;
		cin >> testcase;
		for (int i = 0; i < testcase + 1; i++)
		{
			cin >> val[i];
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < testcase; j++)
			{
				if (order[i] == val[j])
				{
					save.push_back(val[j]);
				}
			}
		}

		for (int i = 0; i < save.size(); i++)
		{
			cout << save[i] << " ";
		}
	}
	return 0;
}