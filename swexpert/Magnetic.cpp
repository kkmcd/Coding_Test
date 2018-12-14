#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;


int main() {
	for (int k = 0; k < 10; k++)
	{
		int map[MAX][MAX] = { 0 };
		int arr[MAX][MAX] = { 0 };

		int sum = 0;
		int siz = 0;
		cin >> siz;

		for (int i = 0; i < siz; i++)
		{
			for (int j = 0; j < siz; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int j = 0; j < siz; j++)
		{
			for (int i = 0; i < siz; i++)
			{
				if(map[i][j] == 1)
				{
					break;
				}
				else if (map[i][j] == 2) {
					map[i][j] = 0;
				}
				else {
					continue;
				}
			}
		}
		for (int j = 0; j < siz; j++)
		{
			for (int i = siz-1; i >= 0; i--)
			{
				if (map[i][j] == 2)
				{
					break;
				}
				else if (map[i][j] == 1) {
					map[i][j] = 0;
				}
				else {
					continue;
				}
			}
		}

		for (int j = 0; j < siz; j++)
		{
			int row = 0;
			for (int i = 0; i < siz; i++)
			{
				if (map[i][j] == 1 || map[i][j] == 2)
				{
					arr[row][j] = map[i][j];
					row++;
				}
			}
		}

		for (int j = 0; j < siz; j++)
		{
			for (int i = 0; i < siz; i++)
			{
				if (arr[i][j] == (1 || 2) && (arr[i+1][j] != arr[i][j]))
				{
					sum += 1;
					i++;
				}
			}
		}
		cout << "#" << k+1 << " "<< sum << endl;
	}
}