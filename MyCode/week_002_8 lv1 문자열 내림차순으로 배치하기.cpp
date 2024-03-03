/*
	sort(string.begin() string.end(), greater<char>()); 이거로 가넝 ㅠㅠ
	https://school.programmers.co.kr/learn/courses/30/lessons/12917
*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {

	vector<int> temp = vector<int>(0);
	for (char single : s) {
		temp.push_back(static_cast<int>(single));
	}

	sort(temp.begin(), temp.end(), greater<int>());

	string out = {};
	for (auto single : temp)
	{
		out += static_cast<char>(single);
	}

	return out;
}

void main() {
	cout << solution("Zbcdefg");
}