/*
https://school.programmers.co.kr/learn/courses/30/lessons/12981
*/

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool isValid(const string& preString, const string& word)
{
	if (preString.back() == word.front())
		return true;

	return false;
}

vector<int> solution(int n, vector<string> words) {
	set<string> answerSet = set<string>();

	// init
	int round = 0;
	int turn = 1;
	string lastWord="";
	for (int i = 0; i < words.size(); i++)
	{
		round = i + 1;

		//끝말잇기에 실패한 경우
		if (lastWord.compare("")!=0 && (false == isValid(lastWord, words.at(i))))
			return vector<int>{((i% n) + 1), turn}; //순번, 갯수

		//중복이면 return
		if (answerSet.find(words.at(i))!=answerSet.end())
			return vector<int>{((i% n) + 1), turn}; //순번, 갯수

		if (round % n == 0)
			++turn;

		lastWord = words.at(i);
		answerSet.insert(words.at(i));
	}

	return vector<int>{0, 0};
}



void main()
{
	vector<string> input = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	auto result = solution(3, input);
	for (const auto& value : result)
	{
		cout << value << ", ";
	}
}