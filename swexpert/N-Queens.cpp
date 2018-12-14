#include <iostream>
#include <math.h>
using namespace std;

int map[10][10] = { 0, };
int n = 0;
int col[10] = { 0 };

//��ü������ memorization�� ���� �ʰ�, ���� ã�� ���.
bool promising(int level) //backtracking�� pruning
{
	for (int i = 1; i < level; i++)
	{
		if (col[i] == col[level]) //���� ���� �ִ� ���� �ִ��� ã�ƺ�
			return false;
		else if(level-i== abs(col[level]-col[i])) // �밢���� ���� ���� �ִ��� ã�ƺ�
			return false;
	}
	return true;
}

bool find(int level)
{
	if (!promising(level)) // ���� �� �� �ִ��� ��.
		return false;
	else if (level == n) // ������ ���
	{
		for (int i = 1; i <= n; i++)
		{
			cout << i << "," << col[i] << endl;
		}
		return true;
	}

	for (int i = 1; i <= n; i++) // ��� ���� ���� �ΰ� ��.
	{
		col[level + 1] = i; //col�� ���� �ְ�, �� ������.
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