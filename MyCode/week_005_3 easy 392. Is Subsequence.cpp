#include<string>
#include<iostream>
#include<set>

// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (s.length() <= 0)
            return true;

        if (t.length() == 0 && s.length() == 0)
            return true;

        int innerIter = 0;
        int count = 0;
        for (int i = 0; i < s.length();i++)
        {
            for (; innerIter < t.length();)
            {
                if (s.at(i) == t.at(innerIter))
                {
                    ++innerIter;
                    ++count;
                    break;
                }
                else {
                    ++innerIter;
                    continue;
                }
            }
        }

        if (count==s.length())
            return true;

        return false;
    }
};

void main()
{
    string p1 = "axc";
    string p2 = "ahbgdc";
    Solution slt = Solution();
    bool result = slt.isSubsequence(p1, p2);
    cout << result;

    return;
}