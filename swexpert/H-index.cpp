#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> cit = { 3,0,6,1,5,2,4 };
//h번 이상 인용된 h개의 논문이 있으면 이때의 h 를 리턴하면 됩니다.
//3번 이상 인용된 논문이 4개 있으면 3을 리턴하고,
//4번 이상 인용된 논문이 3개 있으면 3을 리턴합니다.
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