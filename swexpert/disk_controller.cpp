#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;
vector<int> wait;
vector<int> proc;
class comp {
	bool oper(const vector<int>& a, const vector<int>& b)
	{
		if (a.front() < b.front())
			return false;
		return true;
	}
};

priority_queue<vector<int>,vector<vector<int>>,comp> pq; //비교기를 넣을 때에는 class를 넣어야한다.

int solution(vector<vector<int>> jobs)
{
	int answer = 0;
	sort(jobs.begin(), jobs.end());
	int lastTime = jobs[0][0], i = 1;
	pq.push(jobs[0]);



	//while(!jobs.empty())
	//{
	//	cout << jobs.back().front() << ",";
	//	cout << jobs.back().back() << endl;
	//	jobs.pop_back();
	//}
	
	wait.push_back(jobs.back().front());
	proc.push_back(jobs.back().back());
	
	while (1) {

	}
	return answer;
}

int main() {

	vector<vector<int>> vec = { {1,9},{0,3}, {2,6} };
	solution(vec);

	return 0;
}