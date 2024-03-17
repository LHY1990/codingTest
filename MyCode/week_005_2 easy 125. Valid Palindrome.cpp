#include<string>
#include<iostream>
#include<vector>

// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> input = vector<int>(0);

        // filtering
        int current = 0;
        for (const auto& single : s)
        {
            current = static_cast<int>(single);
            if ('0' <= current && current <= '9')
            {
                input.push_back(current);
            }
            else if ('A' <= current && current <= 'Z')
            {
                input.push_back(current + 32);
            }
            else if ('a' <= current && current <= 'z')
            {
                input.push_back(current);
            }
            else {
                continue;
            }
        }

        if (input.size() <= 1)
            return true;

        int offset = 0;
        int half = input.size() / 2;
        if (input.size() % 2 == 0)
            offset = half;
        else
            offset = half + 1;

        int count = 1;
        for (int i = offset; i < input.size(); i++)
        {
            if (input.at(i) != input.at(half - (count++)))
                return false;
        }


        return true;
    }
};

void main()
{
    string p1 = "1";
    Solution slt = Solution();
    bool result = slt.isPalindrome(p1);
    cout << result;

    return;
}