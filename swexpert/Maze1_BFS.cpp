#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define MAX 100
using namespace std;

int map[MAX][MAX] = { 0 };
bool visit[MAX][MAX] = { 0 };
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
string tmp;

int bfs()
{
	q.push(make_pair(1, 1));

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 3)
			{
				return 1;
			}
			if (nx < 100 && nx >= 0 && ny < 100 && ny >= 0 && visit[nx][ny] != 1 && map[nx][ny] != 1) {
				q.push(make_pair(nx, ny));
			}
		}
	}
	return 0;
}

int main() {
	visit[1][1] = 1;
	for (int l = 0; l < 10; l++)
	{
		int no = 0;
		cin >> no;
		for (int k = 0; k < 100; k++)
		{
			cin >> tmp;

			for (int p = 0; p < tmp.length(); p++)
			{
				map[k][p]=tmp[p]-'0';
			}
		}
		cout << bfs() << endl;
	}
	return 0;
}
