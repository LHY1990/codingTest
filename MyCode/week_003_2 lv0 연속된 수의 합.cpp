/*
https://school.programmers.co.kr/learn/courses/30/lessons/120923
다른 사람 코드에 비해 너무 장황하다. 수학적으로 접근할것
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int sum(vector<int>* list, const int num)
{
	int sum = 0;
	int offset = list->size() - num;
	for (auto iter = list->begin()+offset; iter != list->end(); iter++)
	{
		sum += *iter;
	}
	return sum;
}

vector<int> solution(int num, int total) {

	auto avr = static_cast<float>(total) / num;
	int begin = avr - num / 2 - 1;

	vector<int> numList = vector<int>(0);
	for (; begin < 1000; begin++)
	{
		numList.push_back(begin);

		if (numList.size() >= num)
		{
			if (total == sum(&numList, num))
			{
				vector<int> result(numList.begin() + (numList.size() - num), numList.end());
				return result;
			}
		}

	}


	return vector<int>(0);
}

void main()
{
	auto temp = solution(5, 5);
	for (auto single : temp)
	{
		cout << single << " ";
	}
}