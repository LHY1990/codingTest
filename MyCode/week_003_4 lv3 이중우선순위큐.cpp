/*
https://school.programmers.co.kr/learn/courses/30/lessons/42628
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
		
	vector<int> result = vector<int>(0);

	int intValue = 0;
	string temp;
	for (auto single : operations)
	{
		temp = single.substr(2, single.length() - 2);
		intValue = stoi(temp);

		if (single.at(0) == 'I')
		{
			result.push_back(intValue);
		}
		else if (single.at(0) == 'D')
		{
			if (result.size() == 0)
				continue;

			sort(result.begin(), result.end(), greater<int>());

			// 최대값 삭제
			if (intValue == 1)
			{
				result.erase(result.begin());
			}
			//최소값 삭제
			else if (intValue == -1)
			{
				result.erase(result.begin()+result.size()-1);
			}
		}
	}

	sort(result.begin(), result.end(), greater<int>());

	if (result.size() == 0)
		return vector<int>{0, 0};
	else
		return vector<int>{result.at(0), result.at(result.size() - 1)};

	return result;
}

void main()
{
	auto temp = vector<string>{ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	solution(temp);
	
	auto intList = solution(temp);
	cout << intList.at(0) << " " << intList.at(1);

}