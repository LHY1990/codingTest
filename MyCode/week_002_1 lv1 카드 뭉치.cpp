/*
https://school.programmers.co.kr/learn/courses/30/lessons/159994
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

	auto index1 = cards1.begin();
	auto index2 = cards2.begin();

	int correct = 0;
	for (int i = 0; i < goal.size(); i++)
	{
		if (index1 != cards1.end() && (*index1).compare(goal.at(i)) == 0) {
			++index1;
			++correct;
		}
		else if((index2 != cards2.end() && (*index2).compare(goal.at(i)) == 0)){
			++index2;
			++correct;
		}
		else {
			return "No";
		}
	}

	if (goal.size()== correct)
		return "Yes";

	return "No";
}


void main()
{
	auto temp1 = vector<string>{ "i", "want","to" };
	auto temp2 = vector<string>{ "drink", "water"};
	auto temp3 = vector<string>{ "i", "want", "to", "drink", "water" };

	cout << solution(temp1, temp2, temp3) << endl;
	return;
}