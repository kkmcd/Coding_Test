#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> cit = { 3,0,6,1,5,2,4 };
//h�� �̻� �ο�� h���� ���� ������ �̶��� h �� �����ϸ� �˴ϴ�.
//3�� �̻� �ο�� ���� 4�� ������ 3�� �����ϰ�,
//4�� �̻� �ο�� ���� 3�� ������ 3�� �����մϴ�.
int solution(vector<int> citations) {

	int answer = 0;	
	sort(citations.begin(), citations.end());
	for (int i = citations.size() - 1; i >= 0; i--)
	{
		if (citations[i] <= citations.size() - i) {
			answer = i+1;
			//cout << answer << endl;
			return answer;
		
		}
	}
}

int main() {
	//solution(cit);

	int num = 1234567890;
	char tmp[256];

	_itoa_s(num, tmp, 9);
	cout << tmp << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << tmp[i] << "\t" << (int)tmp - '0' << endl;
	}

	return 0;
}