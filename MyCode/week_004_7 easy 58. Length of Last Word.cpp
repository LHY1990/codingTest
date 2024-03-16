#include<string>
#include<iostream>

// https://leetcode.com/problems/length-of-last-word/submissions/1205183678/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        bool isCount = false;

        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (false == isCount)
            {
                if (s.at(i) == ' ')
                    continue;
                else
                    isCount = true;
            }

            if (s.at(i) == ' ')
                break;
            else
                ++result;
        }

        return result;
    }
};

void main()
{
    string temp = "Wor ld  ";

    Solution slt = Solution();
    int result = slt.lengthOfLastWord(temp);

    cout << result;

    return;
}