// https://leetcode.com/problems/palindrome-number/description/

#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>


using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        string input = to_string(x);
        for (int i = 0; i < input.size() / 2; i++)
        {
            if (input.at(i) != input.at(input.size() - 1 - i))
                return false;

        }

        return true;
    }
};

void main()
{
    auto p1 = 121;
    Solution slt = Solution();
    int result = slt.isPalindrome(p1);
    cout << result;

    return;
}

