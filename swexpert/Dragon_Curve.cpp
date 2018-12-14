#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int no = 0;
int arr[20][4] = { 0 };
int dir_map[100][100] = { 0 };
vector<int> tmp;
vector<int> st;

void curve(int x, int y, int d, int g)
{
	// x와 y의 순서를 바꿔서 입력받아야함
	int tmp_x = x; // 열을 바꿔야한다. 즉, x가 뒤쪽, y가 앞쪽
	int tmp_y = y; // 행을 바꿔야한다.

	int tmp_d = d;
	dir_map[tmp_y][tmp_x] = d;
	st.push_back(tmp_d);

	for (int i = 0; i < g; i++) {
		tmp.clear(); // tmp clear
		tmp.assign(st.begin(), st.end()); //st복사
		st.clear();

		while (!tmp.empty()) {

			tmp_d = tmp.back();
			tmp.pop_back();
			st.push_back(tmp_d);
			if (tmp_d == 0) {
				st.push_back(1);
				tmp_x = tmp_x + 1;
				dir_map[tmp_y][tmp_x] = 1;
			}
			else if (tmp_d == 1) {
				st.push_back(2);
				tmp_y = tmp_y - 1;
				dir_map[tmp_y][tmp_x] = 2;
			}
			else if (tmp_d == 2) {
				st.push_back(3);
				tmp_x = tmp_x - 1;
				dir_map[tmp_y][tmp_x] = 3;
			}
			else if (tmp_d == 3) {
				st.push_back(0);
				tmp_y = tmp_y + 1;
				dir_map[tmp_y][tmp_x] = 0;
			}
		}
	}
}

int main() {
	cin >> no;
	for (int i = 0; i < no; i++)
	{
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < no; i++)
	{
		int x = arr[i][0];
		int y = arr[i][1];
		int d = arr[i][2];
		int g = arr[i][3];

		curve(x, y, d, g);
	}
	cout << endl << endl;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cout << dir_map[i][j];
		}
		cout << endl;
	}
	return 0;
}