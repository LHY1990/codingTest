/*
https://school.programmers.co.kr/learn/courses/30/lessons/120846
*/

#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool isCompositeNumber(const int number)
{
	int count{0};

	if (number < 4)
		return false;

	const int half = static_cast<int>(number / 2);

	for (int i = 1; i <= half; i++)
	{
		if ((number % i) == 0)
			++count;

		
	}
	//자기자신
	++count;

	if (count >= 3)
		return true;

	return false;
}

int solution(int n) {
	
	if (n < 4)
		return 0;
	
	int result = 0;

	for (int i = 4; i <= n; i++)
	{
		if (isCompositeNumber(i))
			++result;
	}

	return result;
}

void main()
{
	int count = solution(15);
	cout << count;
}