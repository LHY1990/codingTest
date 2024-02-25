/*
https://school.programmers.co.kr/learn/courses/30/lessons/12985 
*/

#include <iostream>

using namespace std;

bool isNearBy(const int lValue, const int rValue)
{
	return (lValue + rValue) >= 2;
}

void setNextRound(int& currentUserCount, int* userList, int& round)
{
	if (currentUserCount < 2) {
		return;
	}

	int outIndex = 0;
	for (int i = 0; i < currentUserCount; i += 2)
	{
		if ((userList[i] + userList[i + 1]) > 0)
			userList[outIndex] = 1;
		else
			userList[outIndex] = 0;

		++outIndex;
	}

	++round;

	currentUserCount /= 2;
}

int solution(int n, int a, int b)
{
	int currentUserCount = n;
	int* userList = new int[currentUserCount] {};
	
	userList[a - 1] = 1;
	userList[b - 1] = 1;

	int round = 1;
	int i = 0;
	while (true)
	{
		for (i=0; i < currentUserCount; i += 2)
		{
			if (isNearBy(userList[i], userList[i + 1]))
			{
				delete[] userList;
				return round;
			}
		}

		setNextRound(currentUserCount, userList, round);
	}

	return round;
}

void main()
{
	int round = solution(8, 4, 7);
	cout << round << endl;
}