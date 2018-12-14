#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	deque<int> prog_dq;
	deque<int> speed_dq;
	vector<int> tmp;
	int i = 1;
	for (int i = 0; i < progresses.size(); i++)
	{
		prog_dq.push_back(progresses[i]);
		speed_dq.push_back(speeds[i]);
	}
		while (!prog_dq.empty())
		{
			if (prog_dq.front() + speed_dq.front()*i > 100)
			{
				while (1)
				{
					if (prog_dq.front() + speed_dq.front()*i > 100) {
						tmp.push_back(prog_dq.front());
						prog_dq.pop_front();
						speed_dq.pop_front();
					}
					else
					{
						answer.push_back(tmp.size());
						tmp.clear();
						i = 1;
						break;
					}
				}
			}
			else {
				i++;
			}
		}
	return answer;
}