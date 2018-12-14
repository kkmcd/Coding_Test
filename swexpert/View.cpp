#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num = 0;
int height[1000][1000];
int main() {


	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> height[i][j];
		}
		int ans = 0;
		for (int j = 0; j < num; j++)
		{
			if (!(height[i][j] > height[i][j+1] && height[i][j] > height[i][j+2] && height[i][j] > height[i][j-1] && height[i][j] > height[i][j-2])) continue;
			else
			{
				int y = max(max(height[i][j + 1], height[i][j + 2]), max(height[i][j-1],height[i][j-2]));
				ans += height[i][j] - y;
			}
		}
		cout << "#" << i+1 << " " << ans << endl;
	}

	return 0;
}