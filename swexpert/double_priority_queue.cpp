#include <deque>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// heap ���������� deque�� Ǭ��.
vector<int> solution(vector<string> arguments)
{
	vector<int> answer;
	deque<int> deq;
	
	for (int i = 0; i < arguments.size(); i++)
	{
		string s = arguments[i];
		int num = stoi(s.substr(2)); //������ ������ ����� ���� substr�� ����Ѵ�! substr(2)�ϸ�, 2�� �ε����� ����! ��, 3��°������ �������Ե�.
		if (s.substr(0, 1) == "I") // ���� ������ ���� �ʴ���, substr�� ����ϸ� ���� �о�� �� �ִ�!
		{
			deq.push_front(num); //���� �Է��Ѵ�.
			if (deq.size() > 1) { // ����ִ��� üũ.
				for (int i = 0; i < deq.size() - 1; i++) 
				{
					if (deq[i] > deq[i + 1]) swap(deq[i], deq[i + 1]); //bubble sort ���. �Էµ� ������ üũ. q, deque �� �ڷᱸ�������� ȿ����
					else break;
				}
			}
		}
		else {
			if (!deq.empty()) { // ��������� ������ üũ.
				if (num == 1) deq.pop_back();
				else deq.pop_front();
			}
		}
	}
	if (deq.empty()) { // empty�� ��쿡 ����ó��
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(deq.back());
		answer.push_back(deq.front());
	}
	return answer;
}