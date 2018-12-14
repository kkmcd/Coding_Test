#include <iostream>

using namespace std;

char set[10];
bool mem[10];
int n = 0;

void powerset(int level)
{
	if (level == n ) { // 내가 짰던건 level == n일때는 true 주고, if문 밖에서 for문을 돌림. but 이렇게 하면 너무 많은 애들이 나옴
		for (int i = 0; i < n; i++)
		{
			if (mem[i])
				cout << set[i] << " ";
		}
		cout << endl;
		return;
	}

	// mem을 통해 각각의 집합을 포함하는 경우와 포함하지 않는 경우로 나눠서 풀게됨.
	// 단, mem은 level로 하고, powerset에서 level+1을 줌.
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