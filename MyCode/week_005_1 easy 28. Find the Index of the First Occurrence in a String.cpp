#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length())
            return -1;

        for (int i = 0; i <= haystack.length() - needle.length();++i)
            if (haystack.at(i) == needle.at(0))
                if (haystack.substr(i, needle.length()).compare(needle) == 0)
                    return i;

        return -1;
    }
};

void main()
{
    string p1 = "aaa";
    string p2 = "aaaa";
    Solution slt = Solution();
    int result = slt.strStr(p1, p2);
    cout << result;

    return;
}