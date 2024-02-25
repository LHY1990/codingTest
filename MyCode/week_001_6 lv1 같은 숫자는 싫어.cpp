/*
https://school.programmers.co.kr/learn/courses/30/lessons/12906
*/

#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> outList = vector<int>(0);
    for (int single : arr)
    {
        if (outList.size() == 0)
        {
            outList.push_back(single);
            continue;
        }

        if (outList.back() != single)
        {
            outList.push_back(single);
        }
    }

    return outList;
}

void main()
{

    auto list = solution(vector<int>{1, 1, 3, 3, 0, 1, 1});
    for (auto single : list)
        cout << single << ", ";
}