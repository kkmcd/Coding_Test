#include <iostream>
using namespace std;

long long square(int n, int k)
{
	long long mul = n;
	if (k != 1) mul *= square(n, k - 1);
	else
		return mul;
}

int main() {

	int idx, n, k;

	for (int i = 0; i < 10; i++) {
		cin >> idx;
		cin >> n;
		cin >> k;
		cout <<"#" << idx <<" "<< square(n, k) << endl;
	}
	return 0;
}

