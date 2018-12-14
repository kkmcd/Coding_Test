#include <iostream>
#include <math.h>
using namespace std;

int map[10][10] = { 0, };
int n = 0;
int col[10] = { 0 };

//전체적으로 memorization을 하지 않고, 값을 찾는 방식.
bool promising(int level) //backtracking의 pruning
{
	for (int i = 1; i < level; i++)
	{
		if (col[i] == col[level]) //같은 열에 있는 말이 있는지 찾아봄
			return false;
		else if(level-i== abs(col[level]-col[i])) // 대각선에 같은 값이 있는지 찾아봄
			return false;
	}
	return true;
}

bool find(int level)
{
	if (!promising(level)) // 말을 둘 수 있는지 봄.
		return false;
	else if (level == n) // 끝나는 경우
	{
		for (int i = 1; i <= n; i++)
		{
			cout << i << "," << col[i] << endl;
		}
		return true;
	}

	for (int i = 1; i <= n; i++) // 모든 열에 말을 두게 함.
	{
		col[level + 1] = i; //col에 값을 넣고, 다 돌려봄.
		if (find(level + 1))
			return true;
	}
	return false;
}


int main() {
	cin >> n;
	find(0);
	return 0;
}