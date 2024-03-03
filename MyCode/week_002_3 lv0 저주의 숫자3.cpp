/*
https://school.programmers.co.kr/learn/courses/30/lessons/120871
*/

#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n) {

	if (n == 0)
		return 0;

	vector<int> list = vector<int>(0);
	int number = 0;
	string strNum = "";
	while (list.size() < n)
	{
		++number;
		strNum = to_string(number);

		if (number % 3 == 0) {
			continue;
		}
		else if (strNum.find("3") != string::npos) {
			continue;
		}

		list.push_back(number);
	}

	return list.back();
}

void main()
{
	cout<<"end: " << solution(40) << endl;


	return;
}