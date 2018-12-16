#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int first[5] = { 1,2,3,4,5 };
	int second[8] = { 2,1,2,3,2,4,2,5 };
	int third[10] = { 3,3,1,1,2,2,4,4,5,5 };

	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < answers.size(); i++)
	{
		if (first[i % 5] == answers[i])		a++;
		if (second[i % 8] == answers[i])	b++;
		if (third[i % 10] == answers[i])	c++;
	}

	int mx = max(a, max(b, c));
	if (mx == a)
		answer.push_back(1);
	if (mx == b)
		answer.push_back(2);
	if (mx == c)
		answer.push_back(3);
	
	return answer;
}

int main() {

	vector<int> answers = { 1,3,2,4,2 };
	solution(answers);


	return 0;
}