/*
https://school.programmers.co.kr/learn/courses/30/lessons/12909
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool solution(const char* s) {
	const char left = '(';
	const char right = ')';

	int status = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == left)
			++status;
		else if (s[i] == right)
			--status;

		if (status < 0)
			return false;
	}
	
	
	return status==0;
}

void main()
{
	bool result = solution("(()))");
	cout << int(result) << endl;
}