#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int map[9][9] = { 0 };
int cpy[9][9] = { 0 };
int row = 0, col=0;
deque<pair<int, int>> cor;

void find() {
	if (map[0][0] != 0 && map[0][0] != 6)
	{
		cor.push_back({ 0,0 });
	}
	if (map[0][col - 1] != 0 && map[0][col - 1] != 6)
	{
		cor.push_back({ 0,col-1 });
	}

	if (map[row - 1][0] != 0 && map[row - 1][0] != 6)
	{
		cor.push_back({ row-1,0 });
	}
	if (map[row - 1][col - 1] != 0 && map[row - 1][col - 1] != 6)
	{
		cor.push_back({ row-1,col-1});
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == col - 1) || (i == row - 1 && j == 0) || (i == row - 1 && j == col - 1)) continue;
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				cor.push_back({ i,j });
			}
		}
	}
}

void mv_right(int x, int y)
{
	while (1)
	{
		if (map[x][y] == 6) return;
		if (y >= col) return;
		cpy[x][y] = 8;
		y = y + 1;
	}
}

void mv_left(int x, int y)
{
	while (1)
	{
		if (map[x][y] == 6) return;
		if (y < 0) return;
		cpy[x][y] = 8;
		y = y - 1;
	}
}

void mv_up(int x, int y)
{
	while (1)
	{
		if (map[x][y] == 6) return;
		if (x < 0) return;
		cpy[x][y] = 8;
		x = x - 1;
	}
}

void mv_down(int x, int y)
{
	while (1)
	{
		if (map[x][y] == 6) break;
		if (x >= row) break;
		cpy[x][y] = 8;
		x = x + 1;
	}
}

int right(int x, int y)
{
	int cnt = 0;
	while (1) {
		if (map[x][y] != 6) {
			y = y + 1;
			if (cpy[x][y] == 0 && y < col) {
				cnt = cnt + 1;
			}
		}
		//if (map[x][y] != 6 && map[x][y] != 0 && cpy[x][y] != 8) cnt = cnt - 1;
		if (y >= col || map[x][y] == 6)
		{
			cout << "right : " << cnt << endl;
			return cnt - 1;
		}
	}
}

int left(int x, int y)
{
	int cnt = 0;
	while (1) {
		if (map[x][y] != 6) {
			y = y - 1;
			if (cpy[x][y] == 0 && y > 0) {	
				cnt = cnt + 1;
			}
		}
		//if (map[x][y] != 6 && map[x][y] != 0) cnt = cnt - 1;
		if (y < 0 || map[x][y] == 6) {
			cout << "left : " << cnt << endl;
			return cnt - 1;
		}
	}
}

int up(int x, int y)
{
	int cnt = 0;
	while (1) {
		if (map[x][y] != 6) {
			x = x - 1;
			if (cpy[x][y] == 0 && x > 0) {
				cnt = cnt + 1;
			}
		}
		//if (map[x][y] != 6 && map[x][y] != 0) cnt = cnt - 1;
		if (x < 0 || map[x][y] == 6) {
			cout << "up : " << cnt << endl;
			return cnt - 1;
		}
	}
}

int down(int x, int y)
{
	int cnt = 0;
	while (1) {
		if (map[x][y] != 6) {
			x = x + 1;
			if (cpy[x][y] == 0 && y < col) {
				cnt = cnt + 1;
			}
		}
		//if (map[x][y] != 6 && map[x][y] != 0) cnt = cnt - 1;
		if (x >= row || map[x][y] == 6)
		{
			cout << "down : " << cnt << endl;
			return cnt - 1;
		}

	}
}

void search() {
	while (!cor.empty()) {
		int x = cor.front().first;
		int y = cor.front().second;
		cor.pop_front();
		int maxval = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (map[i][j] == 6)
					cpy[i][j] = 1;
			}
		}
		if (map[x][y] == 1)
		{
			maxval = max(max(right(x, y), left(x, y)), max(up(x, y), down(x, y)));
			if (maxval == right(x, y))
			{
				mv_right(x, y);
			}
			else if (maxval == left(x, y))
			{
				mv_left(x, y);
			}
			else if (maxval == up(x, y))
			{
				mv_up(x, y);
			}
			else if (maxval == down(x, y))
			{
				mv_down(x, y);
			}
		}

		else if (map[x][y] == 2)
		{
			maxval = max((right(x, y) + left(x, y)), (up(x, y) + down(x, y)));
			if ((right(x, y) + left(x, y)) == maxval)
			{
				mv_right(x, y);
				mv_left(x, y);
			}
			else if (maxval == (up(x, y) + down(x, y)))
			{
				mv_up(x, y);
				mv_down(x, y);
			}
		}

		else if (map[x][y] == 3)
		{
			maxval = max(max(up(x, y) + right(x, y), right(x, y) + down(x, y)), max(down(x, y) + left(x, y), left(x, y) + up(x, y)));

			if (maxval == up(x, y) + right(x, y)) {
				mv_up(x, y);
				mv_right(x, y);
			}
			else if(maxval == right(x,y)+down(x,y))
			{
				mv_right(x, y);
				mv_down(x, y);
			}
			else if (maxval == down(x, y) + left(x, y))
			{
				mv_down(x, y);
				mv_left(x, y);
			}
			else if(maxval == left(x,y)+up(x,y))
			{
				mv_left(x, y);
				mv_up(x, y);
			}
		}

		if (map[x][y] == 4)
		{
			maxval = max(max(left(x, y) + up(x, y) + right(x, y), up(x, y) + right(x, y) + down(x, y)), max(right(x, y) + down(x, y) + left(x, y), down(x, y) + left(x, y) + up(x, y)));

			if(maxval == left(x, y) + up(x, y) + right(x, y))
			{ 
				mv_left(x, y);
				mv_up(x, y);
				mv_right(x, y);
			}
			else if(maxval == up(x, y) + right(x, y) + down(x, y))
			{ 
				mv_up(x, y);
				mv_right(x, y);
				mv_down(x, y);
			}
			else if(maxval == right(x, y) + down(x, y) + left(x, y))
			{ 
				mv_right(x, y);
				mv_down(x, y);
				mv_left(x, y);
			}
			else if(maxval == down(x, y) + left(x, y) + up(x, y))
			{ 
				mv_down(x, y);
				mv_left(x, y);
				mv_up(x, y);
			}
		}

		if (map[x][y] == 5)
		{
			mv_down(x, y);
			mv_left(x, y);
			mv_up(x, y);
			mv_right(x, y);
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << cpy[i][j];
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
int main() {


	cin >> row;
	cin >> col;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
		}
	}

	find();
	search();

	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (cpy[i][j] == 0)
				count++;
		}
	}

	cout << count;
	return 0;
}