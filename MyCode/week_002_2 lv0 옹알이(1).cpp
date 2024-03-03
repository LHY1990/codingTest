/*
https://school.programmers.co.kr/learn/courses/30/lessons/120956
*/

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {

	vector<string> words = vector<string>{ "aya", "ye", "woo", "ma" };
	int temp[10] = {};
	size_t pos{ 0 };
	bool isValid = true;
	int count{ 0 };

	for (string inputWord : babbling)
	{
		memset(&temp, 0, 10 * sizeof(int));
		isValid = true;

		for (string word : words)
		{
			pos = inputWord.find(word);
			if (pos != string::npos)
			{
				for (auto i = pos; i < pos + word.size(); i++)
				{
					temp[i] += 1;
				}
			}
		}

		for (int i = 0; i < inputWord.size(); i++)
		{
			if (temp[i] == 0 || temp[i]>1)
			{
				isValid = false;
			}
		}

		if (isValid) {
			++count;
		}
	}
	return count;
}

void main()
{
	cout << solution(vector<string>{"maya"}) << endl;
	return;

}