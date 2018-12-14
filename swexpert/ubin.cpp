#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int m, n;
int arr[8][8];
int map[8][8];
bool chk[8][8];
bool visit[8][8] = { 0 };
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int cnt, ans;
queue<pair<int, int>> q;

struct cnt_virus {
	int x;
	int y;
};

cnt_virus v[100];



void virus() {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = true;
			if (map[i][j] == 2) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];

			if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
			if (map[xx][yy] == 2 || map[xx][yy] == 1 || visit[xx][yy] == 1) continue;

			q.push({ xx,yy });
			map[xx][yy] = 2;
			visit[xx][yy] = true;


		}

	}

	cout << "---" << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	int vcnt = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) vcnt++;
		}
	}

	ans = max(ans, vcnt);


}

void wall(int w) {
	if (w == 3) {
		virus();
		return;
	}

	for (int a = 0; a < m; a++) {
		for (int b = 0; b < n; b++) {
			if (map[a][b] == 0) {

				map[a][b] = 1;
				wall(w + 1);
				map[a][b] = 0; 

			}

		}
	}

}




int main() {
	cnt = 0;

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				v[cnt].x = i;
				v[cnt].y = j;
				cnt++;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = arr[i][j];
			chk[i][j] = false;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 || map[i][j] == 2) continue;

			map[i][j] = 1; chk[i][j] = true;
			wall(1);
			map[i][j] = 0; chk[i][j] = false;

		}

	}


	cout << ans << endl;

	return 0;
}