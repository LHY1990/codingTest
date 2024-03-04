/*
https://school.programmers.co.kr/learn/courses/30/lessons/142086
if와 else에 중복으로 코드가 들어간것을 풀고나서 확인
*/


#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
	vector<int> out = vector<int>(0);
	map<char, int> preCharMap = map<char, int>();

	for (int i = 0; i < s.size(); i++)
	{
		auto iter = preCharMap.find(s.at(i));
		if (preCharMap.end() == iter)
		{
			out.push_back(-1);
		}
		else {
			out.push_back(i - iter->second);
		}
		preCharMap[s.at(i)] = i;
	}

	return out;
}

void main()
{
	auto temp = solution("foobar");
	for (auto single : temp) {
		cout << single << " ";
	}
}