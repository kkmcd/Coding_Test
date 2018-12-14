#include <deque>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// heap 문제이지만 deque로 푼다.
vector<int> solution(vector<string> arguments)
{
	vector<int> answer;
	deque<int> deq;
	
	for (int i = 0; i < arguments.size(); i++)
	{
		string s = arguments[i];
		int num = stoi(s.substr(2)); //어디부터 어디까지 사용할 때는 substr을 사용한다! substr(2)하면, 2번 인덱스에 접근! 즉, 3번째값부터 가져오게됨.
		if (s.substr(0, 1) == "I") // 굳이 변수에 담지 않더라도, substr을 사용하면 값을 읽어올 수 있다!
		{
			deq.push_front(num); //값을 입력한다.
			if (deq.size() > 1) { // 비어있는지 체크.
				for (int i = 0; i < deq.size() - 1; i++) 
				{
					if (deq[i] > deq[i + 1]) swap(deq[i], deq[i + 1]); //bubble sort 사용. 입력될 때마다 체크. q, deque 등 자료구조에서는 효율적
					else break;
				}
			}
		}
		else {
			if (!deq.empty()) { // 비어있지는 않은지 체크.
				if (num == 1) deq.pop_back();
				else deq.pop_front();
			}
		}
	}
	if (deq.empty()) { // empty인 경우에 예외처리
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(deq.back());
		answer.push_back(deq.front());
	}
	return answer;
}