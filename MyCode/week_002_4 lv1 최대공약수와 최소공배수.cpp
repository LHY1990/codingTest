#include <vector>
#include <iostream>
/*
https://school.programmers.co.kr/learn/courses/30/lessons/12940
*/

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> result = vector<int>(0);
	vector<int> list = vector<int>(0);

	const int small = (n > m) ? m : n;
	const int big = (small == n) ? m : n;

	for (int i = small; i > 0; i--) {
		if (small % i == 0 && big % i == 0) {
			result.push_back(i);
			break;
		}
	}

	if (small == big)
	{
		result.push_back(small);
		return result;
	}

	int temp = big;
	while (true) {

		if (temp % small == 0 && temp % big == 0)
		{
			result.push_back(temp);
			return result;
		}
		temp += big;
	}


	return result;
}

void main()
{
	auto output = solution(3, 12);
	cout << output.at(0) << ":" << output.at(1) << endl;
}