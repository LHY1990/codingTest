#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

// https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        if (strs.at(0).compare("")==0)
            return "";

        const int minLen = strs.at(0).size();

        map<string, int> filter = map<string, int>();
        int len = 1;
        string currendString;
        string lastString = "";

        while (minLen >= len) {
            currendString = strs.at(0).substr(0, len);

            for (const auto& single : strs)
            {
                //같으면 pass
                if (single.substr(0, len).compare(currendString) == 0)
                    continue;
                else
                    return lastString;
            }

            lastString = currendString;
            ++len;
        };

        return lastString;
    }
};
void main()
{
    
    vector<string> input = vector<string>{ "a"};

    Solution slt = Solution();

    string result = slt.longestCommonPrefix(input);
    cout << result;

    return;
}