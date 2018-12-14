#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	string input;
	string find;
	int index;

	for (int k = 1; k <= 10; k++) 
	{
		cin >> index;
		cin >> find;
		cin >> input;
		int cnt = 0;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == find[0])
			{
				for (int j = 1; j < find.length(); j++)
				{
					if (j == find.length() - 1 && find[j]==input[i+j])
					{
						cnt++;
						break;
					}
					else if (input[i + j] == find[j])
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
			else continue;
		}
		cout <<"#" << k << " " << cnt << endl;
	}
	return 0;
}