#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>

// https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int zeroCount = 0;
        for (int i = 0; i < citations.size();++i)
            if (citations.at(i) == 0)
                ++zeroCount;
        

        const int size = citations.size() - zeroCount;
        for (int i = size -1; i >= 0; --i)
        {
            if (i+1 <= citations.at(i))
                return i + 1;
        }

        return size;
    }
};

void main()
{
    auto p1 = vector<int>{ 1,3,1 };
    Solution slt = Solution();
    int result = slt.hIndex(p1);
    cout << result;

    return;
}

