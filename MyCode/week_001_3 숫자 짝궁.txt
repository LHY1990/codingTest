/*
https://school.programmers.co.kr/learn/courses/30/lessons/131128?language=cpp
*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long count(const string& input, char& findChar)
{
	long count = 0;

	for (auto single : input)
	{
		if (findChar == single)
			++count;
	}

	return count;
}

void calcCharCount(const string& input, int* const array)
{
	string list = "0123456789";

	for (char numberChar : list) {
		array[numberChar - '0'] = count(input, numberChar);
	}
}

string solution(string X, string Y) {

	int* pXCountList = new int[10] {};
	int* pYCountList = new int[10] {};
	int* pResultList = new int[10] {};

	calcCharCount(X, pXCountList);
	calcCharCount(Y, pYCountList);
	int sameCount = 0;

	for (int i = 0; i < 10; i++)
	{
		pResultList[i] = (pXCountList[i] > pYCountList[i]) ? pYCountList[i] : pXCountList[i];
		sameCount += pResultList[i];
	}

	//중복값이 없다면
	if (sameCount == 0)
		return "-1";

	//중복값이 모두 0이라면
	if (pResultList[0] == sameCount)
		return "0";

	string output = "";

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < pResultList[i]; j++)
			output.push_back('0'+i);
	}

	return output;
}

void main()
{
	string result = solution("1000000002", "20200");
	cout << result;
}