#include <iostream>

using namespace std;

char set[10];
bool mem[10];
int n = 0;

void powerset(int level)
{
	if (level == n ) { // ���� ®���� level == n�϶��� true �ְ�, if�� �ۿ��� for���� ����. but �̷��� �ϸ� �ʹ� ���� �ֵ��� ����
		for (int i = 0; i < n; i++)
		{
			if (mem[i])
				cout << set[i] << " ";
		}
		cout << endl;
		return;
	}

	// mem�� ���� ������ ������ �����ϴ� ���� �������� �ʴ� ���� ������ Ǯ�Ե�.
	// ��, mem�� level�� �ϰ�, powerset���� level+1�� ��.
	mem[level] = 0; 
	powerset(level + 1);
	mem[level] = 1; 
	powerset(level + 1);
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> set[i];
	}

	powerset(0);

	return 0;
}