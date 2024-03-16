#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>


// https://leetcode.com/problems/roman-to-integer/submissions/1205177422/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    unordered_map<char, int> changer = unordered_map<char, int>();
    Solution()
    {
        changer['I'] = 1;
        changer['V'] = 5;
        changer['X'] = 10;
        changer['L'] = 50;
        changer['C'] = 100;
        changer['D'] = 500;
        changer['M'] = 1000;
    }


    int romanToInt(string s) {
        int result = 0;
        int lastValue = changer.find(s.at(s.length() - 1))->second;
        int currentValue =0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            currentValue = changer.find(s.at(i))->second;

            if (currentValue > lastValue)
            {
                result += currentValue;
                lastValue = currentValue;
            }
            else if (currentValue == lastValue)
            {
                result += currentValue;
            }
            else 
            {
                result -= currentValue;
            }
        }

        return result;
    }
};

void main()
{
    string input = "MCMXCIV";

    Solution slt = Solution();
    int result = slt.romanToInt(input);

    cout << result;





    return;
}