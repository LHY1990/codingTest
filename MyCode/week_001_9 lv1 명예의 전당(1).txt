/*
https://school.programmers.co.kr/learn/courses/30/lessons/138477
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getThirdScore(vector<int>& list, const int limit)
{
	if (list.size() == 0)
		return 0;

	if (list.size() == 1)
		return list.at(0);

	if (list.size() == 2)
		return list.at(0) > list.at(1) ? list.at(1) : list.at(0);

	sort(list.begin(), list.end(), greater<int>());

	if (list.size() < limit)
		return list.back();

	return list.at(limit - 1);
}

vector<int> solution(int k, vector<int> score) {

	vector<int> outList = vector<int>(0);
	vector<int> stackList = vector<int>(0);

	for (int i = 0; i<score.size(); i++)
	{
		stackList.push_back(score.at(i));
		outList.push_back(getThirdScore(stackList, k));
	}


	return outList;
}


int main()
{
	auto input = vector<int>{ 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 };
	vector<int> resultList = solution(4, input);
	for (auto single : resultList)
	{
		cout << single << ", ";
	}
	return 0;
}