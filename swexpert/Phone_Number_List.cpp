#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (int i = 0; i < phone_book.capacity(); i++)
	{
		for (int j = 0; j < phone_book.capacity(); j++)
		{
			if (i == j) continue;
			if (phone_book[i][0] == phone_book[j][0])
			{
				if (phone_book[i] == phone_book[j].substr(0, phone_book[i].length())) {
					answer = false;
					return answer;
				}
			}
		}
	}
	
	return answer;
}