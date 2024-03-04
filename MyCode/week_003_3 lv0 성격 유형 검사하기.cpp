/*
https://school.programmers.co.kr/learn/courses/30/lessons/118666
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    
    map<char, int> result = {
        pair<char,int>('R', 0),
        pair<char,int>('T', 0),
        pair<char,int>('F', 0),
        pair<char,int>('C', 0),
        pair<char,int>('M', 0),
        pair<char,int>('J', 0),
        pair<char,int>('A', 0),
        pair<char,int>('N', 0)
    };
    const int CENTER = 4;

    for (int i = 0; i < survey.size();i++) {
        if (choices.at(i) == CENTER)
            continue;

        if (choices.at(i) < CENTER)
        {
            result[survey.at(i).at(0)] += abs(CENTER - choices.at(i));
        }
        else {
            result[survey.at(i).at(1)] += abs(CENTER - choices.at(i));
        }
    }

    string out;
    out += result['R'] >= result['T'] ? 'R' : 'T';
    out += result['C'] >= result['F'] ? 'C' : 'F';
    out += result['J'] >= result['M'] ? 'J' : 'M';
    out += result['A'] >= result['N'] ? 'A' : 'N';

    return out;
}

void main()
{
    vector<string> input1 = vector<string>{ "AN", "CF", "MJ", "RT", "NA" };
    vector<int> input2 = vector<int>{ 5, 3, 2, 7, 5 };

    cout << solution(input1, input2) << endl;
}