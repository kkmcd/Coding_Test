#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[100][100];
int visit[100][100] = { -1 };
int all = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minVal = 10000;

int main() {

	cin >> all;
	for (int k = 0; k < all; k++)
	{
		int siz = 0;
		cin >> siz;
		for (int i = 0; i < siz; i++)
		{
			for (int j = 0; j < siz; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < siz; i++)
		{
			for (int j = 0; j < siz; j++)
			{
				for (int c = 0; c < 4; c++) {
					if (i + dx[c] >= 0 && i + dx[c] < siz && j + dy[c] >= 0 && j + dy[c] < siz)
					{
						if (map[i][j] > map[i + dx[c]][j + dy[c]])
							map[i][j] += map[i + dx[c][j + dy[c]];
						visit[i][j] = 1;
					}
				}
			}
		}

		cout << map[siz-1][siz-1]<< endl;
	}
	return 0;
}