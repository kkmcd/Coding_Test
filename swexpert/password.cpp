#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int val[100];

void search() {
	for (int i = 0; i < 100; i++)
	{
		int tmp = 100;
		if ((val[i] == val[i + 1] || val[tmp] == val[i]) && val[i] != -1)
		{
			val[i] = -1;
			val[i + 1] = -1;
			int k = 1;
			while (1)
			{
				if (val[i - k] == val[i + k + 1] && val[i - k] != -1)
				{
					val[i - k] = -1;
					val[i + k + 1] = -1;
					k++;
				}
				else {
					tmp = i - k;
					i = k + i+1;
					break;
				}
			}
		}
	}
}

int main() {
	for (int k = 0; k < 10; k++)
	{
		int size;
		int temp;
		string tmp;
		cin >> size;
		cin >> tmp;
		for (int p = 0; p < size; p++)
		{
			val[p] = tmp[p] - '0';
		}
		search();

		for (int i = 0; i < 100; i++)
		{
			if (val[i] != -1)
				cout << val[i];
		}
		cout << endl;
		memset(val, -1, 100);
	}

	return 0;
}