#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int arr[10][100][100] = { 0 };
	int num[10];
	for (int k = 0; k < 10; k++)
	{
		cin >> num[k];
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[k][i][j];
			}
		}
	}

	for (int k = 0; k < 10; k++)
	{
		int crosssuml[100] = { 0 };
		int crosssumr[100] = { 0 };
		int colsum[100] = { 0 };
		int rowsum[100] = { 0 };
		int col = 0;
		int row = 0;
		int maxVal = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				rowsum[i] += arr[k][i][j];
				colsum[j] += arr[k][i][j];
				if (i == j)
				{
					crosssuml[i] += arr[k][i][j];
				}
				if (i == 99 - j)
				{
					crosssumr[i] += arr[k][i][j];
				}
			}
		}

		for (int i = 0; i < 100; i++)
		{
			if(maxVal < max(max(rowsum[i], colsum[i]), max(crosssuml[i], crosssumr[i])))
				maxVal = max(max(rowsum[i],colsum[i]),max(crosssuml[i],crosssumr[i]));
		}

		cout << "#" << k+1 <<" "<< maxVal << endl; 
	}
	return 0;
}