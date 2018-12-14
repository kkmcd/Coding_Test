#include <iostream>
#include <algorithm>
using namespace std;


int val[10][100];
int num[10];
int main() {

	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
		for (int j = 0; j < 100; j++)
		{
			cin >> val[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < num[i]; k++)
		{
			int min = 100, max = 0;
			int minx, miny = 0;
			int maxx, maxy = 0;

			for (int j = 0; j < 100; j++)
			{

				if (min > val[i][j])
				{
					min = val[i][j];
					miny = j;
				}
				if (max < val[i][j]) {
					max = val[i][j];
					maxy = j;
				}
			}
			val[i][maxy] -= 1;
			val[i][miny] += 1;
		}
		int min = 100, max = 0;
		for (int j = 0; j < 100; j++)
		{
			if (min > val[i][j])
			{
				min = val[i][j];
			}
			if (max < val[i][j])
			{
				max = val[i][j];
			}
		}

		cout <<"#" << i+1 << " " << max - min << endl;
	}
	return 0;
}