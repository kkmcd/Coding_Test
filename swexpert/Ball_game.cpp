#include <cstdio>
#include <deque>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int map[101][101] = { 0, };
deque<int> q;
int dx[4] = {-1,1,0,0 };
int dy[4] = {0,0,-1,1 };
int cnt = 1;
int N = 0;
int tmp = 0;
int start1 = 0;
int start2 = 0;
int t = 0;
void dfs(int x, int y, int dir, int start1, int start2, int cnt);
void warmhall(int x, int y, int dir, int hall_num,int start1, int start2, int cnt)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <=N; j++)
		{
			if (map[j][i] == hall_num && i != x && j != y)
			{
					dfs(i+dx[dir] , j+dy[dir] , dir, start1, start2, cnt);
			}
		}
	}
}
void dfs(int x, int y, int dir, int start1, int start2, int cnt)
{
	if (t == 3)
		printf("%d %d \n", x, y);
	if (x >= 1 && x <= N && y >= 1 && y <= N) {
		//printf("%d %d\n", x, y);
		if (map[y][x] == -1) {
			{
				printf("ans: %d %d %d %d\n", start1, start2, dir, cnt);
				q.push_back(cnt);
				return;
			}
		}
		if (start1 == x && start2 == y)
		{
			q.push_back(cnt);
			return;
		}
		else if (map[y][x] == 0)
		{
			dfs(x + dx[dir], y + dy[dir], dir, start1, start2, cnt + 1);
		}
	
		else if (map[y][x] == 1)
		{
			if (dir == 0)
			{
				dfs(x, y - 1, 2, start1, start2, cnt + 1);
			}
			else if(dir == 1)
				dfs(x - 1, y, 0, start1, start2, cnt + 1);
			else if(dir== 2)			
				dfs(x, y+1, 3, start1, start2, cnt + 1);
			else if(dir==3)
			{
				dfs(x + 1, y, 1, start1, start2, cnt + 1); 
			}
		}

		if (map[y][x] == 2) {
			if (dir == 0)
			{
				dfs(x, y + 1, 3, start1, start2, cnt + 1);
			}
			else if(dir == 1) dfs(x - 1, y, 0, start1, start2, cnt + 1);
			else if(dir == 2) {
				dfs(x + 1, y, 1, start1, start2, cnt + 1);
			}
			else if(dir== 3) dfs(x, y-1, 2, start1, start2, cnt + 1);
		}
		else if (map[y][x] == 3)
		{
			if (dir == 0) dfs(x + 1, y, 1, start1, start2, cnt + 1);
			else if (dir == 1)
			{
				dfs(x, y + 1, 3, start1, start2, cnt + 1);
			}
			else if (dir == 2) {
				dfs(x - 1, y, 0, start1, start2, cnt + 1);
			}
			else if (dir == 3) dfs(x, y-1, 2, start1, start2, cnt + 1);
		}
			
		else if (map[y][x] == 4) {
			if (dir == 0) dfs(x+1, y, 1, start1, start2, cnt + 1);
			else if(dir== 1) {
				dfs(x, y - 1, 2, start1, start2, cnt + 1); 
			}
			else if(dir== 2) dfs(x, y+1, 3, start1, start2, cnt + 1);
			else if(dir== 3) {
				dfs(x - 1, y, 0, start1, start2, cnt + 1);
			}
		}
		else if (map[y][x] == 5)
		{
			if (dir == 0) dfs(x + 1, y, 1, start1, start2, cnt + 1);
			else if (dir == 1) dfs(x - 1, y, 0, start1, start2, cnt + 1);
			else if (dir == 2) dfs(x, y+1, 3, start1, start2, cnt + 1);
			else if (dir == 3) dfs(x, y-1, 2, start1, start2, cnt + 1);
		}
		else if(map[y][x]== 6) {warmhall(x, y, dir, 6, start1, start2, cnt + 1); }
		else if (map[y][x] == 7) {warmhall(x, y, dir, 7, start1, start2, cnt + 1); }
		else if (map[y][x] == 8) {warmhall(x, y, dir, 8, start1, start2, cnt + 1); }
		else if (map[y][x] == 9) {warmhall(x, y, dir, 9, start1, start2, cnt + 1); }
		else if (map[y][x] == 10) {warmhall(x, y, dir, 10, start1, start2, cnt + 1); }
		}
	}

int main() {
	FILE *fp = NULL;
	int tc = 0;
	fopen_s(&fp,"E:\input.txt", "a+");
	fscanf_s(fp, "%d", &tc, sizeof(tc));


	for (t = 1; t<=tc; t++)
	{
		memset(map, 0, sizeof(map));
		fscanf_s(fp, "%d", &N, sizeof(N));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				fscanf_s(fp, "%d", &map[i][j],sizeof(map));
			}
		}
		for (int i = 0; i <= N+1; i++)
		{
			map[0][i] = map[i][0] = map[N + 1][i] = map[i][N + 1] = 5;
		}
		for (int i = 0; i <= N+1; i++) {
			for (int j = 0; j <= N+1; j++) {
				printf_s("%d", map[i][j]);
			}
			printf("\n");
		}

		printf("\n\n");
		//start1 = 9;
		//start2 = 5,
		start1 = 1;
		start2 = 1;
		cnt = 1;
		//dfs(start1, start2,0,start1,start2, cnt);
		for (start1 = 1; start1 <= N; start1++) {
			for (start2 = 1; start2 <= N; start2++)
			{
				if (map[start2][start1] == 0) {
				for (int dir = 0; dir < 4; dir++) {
						dfs(start1+dx[dir], start2+dy[dir], dir, start1, start2, cnt);
					}
				}
			}
		}

		if (!q.empty()) {
			sort(q.begin(), q.end(), less<int>());
			printf("ans: %d\n", q.back());
			q.clear();
		}
	}
	fclose(fp);
	return 0;
}