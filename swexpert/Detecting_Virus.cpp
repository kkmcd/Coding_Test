#include <iostream>
#include <algorithm>
#include <queue>
#define max(a,b) (((a>b))? (a):(b))
#define MAX 8

using namespace std;

int row, col = 0;
int map[MAX][MAX] = { 0 };
int cpy[MAX][MAX] = { 0 };
int visit[MAX][MAX] = { 0 };
int tmp = 0;
queue<pair<int, int>> q;

void search() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = 1;
	cpy[x][y] = 2;
	if (x + 1 < row && (cpy[x + 1][y] == 0 || cpy[x + 1][y] == 2 )&& cpy[x+1][y] != 1 && visit[x+1][y] == 0) dfs(x + 1, y);
	if (x - 1 >= 0 && (cpy[x - 1][y] == 0 || cpy[x - 1][y] == 2) && cpy[x - 1][y] != 1 && visit[x-1][y] == 0) dfs(x - 1, y);
	if (y - 1 >= 0 && (cpy[x][y-1] == 0 || cpy[x][y-1] == 2) && cpy[x][y-1] != 1 && visit[x][y-1] == 0) dfs(x, y - 1);
	if (y + 1 < col && (cpy[x][y+1] == 0 || cpy[x][y+1] == 2) && cpy[x][y+1] != 1 && visit[x][y + 1] == 0) dfs(x, y + 1);
}

void make_wall() {
	search(); //2의 위치들을 찾음.
	for (int i = 0; i < row-2; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 0) {
				cpy[i][j] = 1;
				for (int k = i+1; k < row-1; k++) {
					for (int l = 0; l < col; l++) {
						if (map[k][l] == 0) {
							cpy[k][l] = 1;
							for(int m = k+1; m<row-2;m++){
								for (int n = 0; n < col; n++) {
									if (map[m][n] == 0) {
										cpy[m][n] = 1;
										while (!q.empty()) {
											dfs(q.front().first, q.front().second);
											q.pop();

											int cnt = 0;
											for (int i = 0; i < row; i++)
											{
												for (int j = 0; j < col; j++) {
													if (cpy[i][j] == 0)
														cnt++;
												}
											}
											tmp = max(cnt, tmp);
											cout << "max:"<<tmp << endl;
										}
										memset(visit, 0, sizeof(visit) / size(visit[0]));
										memcpy(cpy, map, sizeof(map) / size(map[0]));									cpy[m][n] = 0;
									}
								}
							}
							cpy[k][l] = 0;
						}
					}
				}
				cpy[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> row;
	cin >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	memcpy(cpy, map, sizeof(map) / size(map));
	make_wall();

	cout << tmp << endl;
	return 0;
}