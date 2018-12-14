#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int visit[100][100] = { 0 };
char arr[100][100]; //���ڰ� ���޾� �ֱ� ������ ���ڷ� �޾ƾ��Ѵ�.
int check = 0;
void find(int i, int j)
{
	visit[i][j] = 1; //visit�� �� ���ش�.
	if (arr[i][j] == '3') {
		check = 1; //check�� ���� 0 �Ǵ� 1�� ���� ����� �� �ְ� �Ѵ�.
		return;
	}
	if ((i - 1 >= 1) && (arr[i - 1][j] != '1') && (visit[i-1][j] == 0)) find(i - 1, j); // i,j�� ���� ���� && ��ġ�� Ȯ�� && visitȮ��
	if ((i+1< 98) && (arr[i + 1][j] != '1') && (visit[i+1][j] == 0)) find(i + 1, j);
	if ((j - 1 >= 1) && (arr[i][j-1] != '1') && (visit[i][j-1] == 0)) find(i, j-1);
	if ((j+1 < 98) && (arr[i][j+1] != '1') && (visit[i][j+1] == 0)) find(i, j+1);
}

int main() {
	visit[1][1] = 1;
	for (int l = 0; l < 10; l++)
	{
		int no = 0;
		cin >> no;
		for (int k = 0; k < 100; k++)
		{
			for (int p = 0; p < 100; p++)
			{
				cin >> arr[k][p];
			}
		}

		find(1, 1);
		cout << "#" << no <<" ";
		if (check == 0) cout << "0"<< endl;
		else if (check == 1) {
			check = 0;
			cout << "1" << endl;
		}
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				visit[i][j] = 0; //visit �ʱ�ȭ
			}
		}
	}
	return 0;
}