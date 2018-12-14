#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[11][31] = { 0 };
int cpy[11][31] = { 0 };
int cpy1[11][31] = { 0 };
int M = 0, N = 0, H = 0, x = 0, y = 0;
int a = 0;
int b = 0;
int c = 0;
int minval = 4;

int search() {
	int row = 0;
	int col = 1;
	int cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		col = i;
		while (row < H)
		{
			row = row + 1;
			if (cpy1[row][col] == 1) {
				col += 1;
			}
			else if (cpy1[row][col - 1] == 1) {
				col -= 1;
			}
		}
		//cout << "result " << i << " : " << col << endl;
		if (i == col) { cnt++; }
		row = 0;
	}
	if (cnt == M) {
		//cout << cnt << endl;
		return 1;
	}
	return -1;
}

void making_wall() {
	for (int i = 1; i <= M-2; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			if ((cpy[j][i] == 0) && (cpy[j][i - 1] == 0) && (i <= M) && (j <= H)) {
				cpy1[j][i] = 1;
				a = 1;
			}
			else a = 0;

			for (int k = i+1; k <= M-1; k++)
			{
				for (int l = 1; l <= H; l++)
				{
					if ((cpy[l][k] == 0) && (cpy[l][k - 1] == 0) && (cpy1[l][k] == 0) && (cpy1[l][k - 1] == 0) && (k <= M) && (l <= H)) {
						cpy1[l][k] = 1;
						b = 1;
					}
					else b = 0;

					for (int m = k+1; m <= M; m++)
					{
						for (int n = 1; n <= H; n++)
						{
							if ((cpy[n][m] == 0) && (cpy[n][m - 1] == 0) && (cpy1[n][m] == 0) && (cpy1[n][m - 1] == 0) && (m <= M) && (n <= H)) {
								cpy1[n][m] = 1;
								c = 1;
							}
							else c = 0;
							int k = search();
							if (k == 1)
							{
								minval = min(minval, a + b + c);
								//cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
								//cout << "min: " << minval << endl;
								//for (int i = 1; i <= H; i++) {
								//	for (int j = 1; j <= M; j++)
								//	{
								//		cout << cpy[i][j];
								//	}
								//	cout << '\n';
								//}
								//for (int i = 1; i <= H; i++) {
								//	for (int j = 1; j <= M; j++)
								//	{
								//		cout << cpy1[i][j];
								//	}
								//	cout << '\n';
								//}
							}
							cpy1[n][m] = cpy[n][m];

						}
					}
					cpy1[l][k] = cpy[l][k];

				}
			}
			cpy1[j][i] = cpy[j][i];
		}
	}
}

int main() {

	cin >> M;
	cin >> N;
	cin >> H;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		map[x][y] = 1;
	}

	memcpy(cpy, map, sizeof(cpy));
	memcpy(cpy1, cpy, sizeof(cpy));
	making_wall();

	return 0;
}