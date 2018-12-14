#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

string tmp;
char map[10][10];
int row, col = 0;
int gx, gy = 0;
queue<pair<int, int>> R;
queue<pair<int, int>> cmp_R;
queue<pair<int, int>> B;
queue<pair<int, int>> cmp_B;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int visitR[10][10] = { 0 };
int visitB[10][10] = { 0 };
int cnt[10][10] = { 0 };

int bfs_R() {

	while (!R.empty()) {	
		int x = R.front().first;
		int y = R.front().second;
		R.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] == 'O') {
				cmp_R.push(make_pair(nx, ny));
				return 1;
			}
			if ((map[nx][ny] == '.' || map[nx][ny] == '0') && visitR[nx][ny] != 1 && map[nx][ny] != '#') //map=='.' || map=='0' 에 반드시 괄호를 붙여야한다. 안붙이면 무한루프뜸!
			{
				while (1) {
					visitR[nx][ny] = 1;
					nx = nx + dx[i];
					ny = ny + dy[i];
					if (map[nx][ny] == 'O') {
						cmp_R.push(make_pair(nx, ny));
						return 1;
					}
					if (map[nx][ny] == '#') {
						nx = nx - dx[i];
						ny = ny - dy[i];
						R.push(make_pair(nx, ny));
						//cmp_R.push(make_pair(nx, ny));
						cout << nx << ny << endl;
						break;
					}
				}
			}

		}
	}
	return -1;
}

int bfs_B() {
	while (!B.empty()) {
		int x = B.front().first;
		int y = B.front().second;
		B.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((map[nx][ny] != '#' || map[nx][ny] == 'O') && visitB[nx][ny] != 1) //map=='.' || map=='0' 에 반드시 괄호를 붙여야한다. 안붙이면 무한루프뜸!
			{
				while (1) {
					visitB[nx][ny] = 1;
					nx = nx + dx[i];
					ny = ny + dy[i];
					if (map[nx][ny] == 'O') {
						cmp_B.push(make_pair(nx, ny));
						return 1;
					}
					if (map[nx][ny] == '#') {
						nx = nx - dx[i];
						ny = ny - dy[i];
						B.push(make_pair(nx, ny));
						cmp_B.push(make_pair(nx, ny));
						break;
					}

				}
			}

		}
	}
	return -1;
}

int main() {

	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		cin >> tmp;
		for (int j = 0; j < col; j++)
		{
			map[i][j] = tmp[j];
			if (map[i][j] == 'R')
			{
				R.push(make_pair(i, j));
			}
			if (map[i][j] == 'B')
			{
				B.push(make_pair(i, j));
			}
		}
	}
	bfs_R();
	bfs_B();

	while (!cmp_R.empty())
	{
		cout << cmp_R.front().first << cmp_R.front().second << endl;
		cmp_R.pop();
	}
	return 0;
}