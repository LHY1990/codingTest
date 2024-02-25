/*
https://school.programmers.co.kr/learn/courses/30/lessons/42888
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#include <string>
#include <vector>

using namespace std;

vector<string> split(string& input, char delemeter)
{
	vector<string> result = vector<string>(0);
	stringstream ss(input);
	string out;

	while (getline(ss, out, delemeter))
	{
		result.push_back(out);
	}

	return result;
}

string convert(string key)
{
	if (key == "Enter")
		return "들어왔습니다.";
	else if (key == "Leave")
		return "나갔습니다.";	
}

const int ACTION = 0;
const int UID = 1;
const int NICKNAME = 2;
const string CHANGE = "Change";
const string LEAVE = "Leave";

vector<string> solution(vector<string> record) {
	vector<vector<string>> recordVector = vector<vector<string>>(0);
	map<string, string> nicknameMap = map<string, string>();
	vector<string> resultVector = vector<string>(0);

	vector<string> splitVector;
	string uid;
	string nickname;
	string action;

	//선가공	
	for (string single : record)
	{
		splitVector = split(single, ' ');
		recordVector.push_back(splitVector);

		//떠나는 경우 nickname이 없음
		uid = splitVector.at(UID);
		action = splitVector.at(ACTION);
		if (action != LEAVE) {
			//닉네임을 가공
			
			nickname = splitVector.at(NICKNAME);

			//uid 최초등록시
			if ((nicknameMap.find(uid) == nicknameMap.end()))
			{
				nicknameMap[uid] = nickname;
			}
			// 닉네임이 등록되어 있는 경우 입장시 또는 변경이다.
			else {
				nicknameMap[uid] = nickname;
			}
		}
		
	}

	//한글화 처리
	for (auto iter = recordVector.begin();iter!=recordVector.end();iter++)
	{
		if (iter->at(ACTION) == CHANGE)
			continue;

		nickname = nicknameMap.find(iter->at(UID))->second;
		action = convert(iter->at(ACTION));
		resultVector.push_back(nickname + "님이 " + action);
	}


	return resultVector;
}

void main()
{
	vector<string> input = vector<string>(0);
	input.push_back("Enter uid1234 Muzi");
	input.push_back("Enter uid4567 Prodo");
	input.push_back("Leave uid1234");
	input.push_back("Enter uid1234 Prodo");
	input.push_back("Change uid4567 Ryan");
		
		

	auto result = solution(input);
	for (auto single : result)
	{
		cout << single << endl;
	}
}