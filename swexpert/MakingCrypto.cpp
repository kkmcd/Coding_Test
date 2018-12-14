#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	for (int k = 0; k < 10; k++)
	{
		int no = 0;
		queue<int> Q;
		int val = 0;
		int arr[8] = { 0 };
		cin >> no;
		for (int i = 0; i < 8; i++)
		{
			cin >> arr[i];
			Q.push(arr[i]);
		}

		while (1) {
			for (int j = 1; j < 6; j++)
			{
				val = Q.front() - j;
				if (val < 0)
				{
					val = 0;
				}
				Q.pop();
				Q.push(val);
				if (Q.back() == 0)
					break;
			}
			if (Q.back() == 0)
				break;

		}
		cout << no << " ";

		for (int p = 0; p < 8; p++)
		{
			cout << Q.front() << " ";
			Q.pop();
		}
		cout << endl;
	}
	return 0;
}