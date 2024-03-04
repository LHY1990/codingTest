/*
https://school.programmers.co.kr/learn/courses/30/lessons/64065
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s.at(i) == '{' || s.at(i) == '}')
        {
            s.erase(s.begin() + i);
        }
    }

    istringstream ss(s);
    string buffer;
    
    map<int, int> countMap = map<int,int>();
    int tempInt;

    while (getline(ss, buffer, ',')) {
        if (buffer.compare("") == 0)
            continue;
        
        tempInt = stoi(buffer);
        if (countMap.find(tempInt) == countMap.end())
            countMap[tempInt] = 1;
        else
            countMap[tempInt] += 1;
        
    }

    map<int, int, greater<int>> reverseMap = map<int, int, greater<int>>();
    for (auto pair : countMap) {
        reverseMap[pair.second] = pair.first;
    }

    vector<int>result = vector<int>(0);
    for (auto single : reverseMap) {
        result.push_back(single.second);
    }


    return result;
}

void main()
{
    auto temp =solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (auto single : temp)
        cout << single << " ";
}