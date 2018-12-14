#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool comp(const string &a, const string &b)
{
	if (a + b > b + a)
		return true; // true는 그대로, false면 자리 변경. 즉, 큰 값이 앞으로 오게됨!
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> arr;

	for (int i = 0; i < numbers.size(); i++) {
		arr.push_back(to_string(numbers[i]));
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < arr.size(); i++) {
		answer += arr[i];
	}

	if (answer[0] == '0')
		answer = "0";
	return answer;
}