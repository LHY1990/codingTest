// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map = unordered_map<int, int>();

        unordered_map<int, int>::iterator iter;

        for (const int& single : nums)
        {
            iter = map.find(single);
            if (iter == map.end())
                map[single] = 1;
            else
                map[single] = iter->second + 1;
        }

        int max = 0;
        int key = 0;
        for (auto mIter = map.begin(); mIter != map.end(); mIter++)
        {
            if (mIter->second > max)
            {
                max = mIter->second;
                key = mIter->first;
            }
        }

        return key;
    }
};


void main()
{
    auto temp = vector<int>{1, 2, 3, 3, 3, 2, 2, 2, 2};
    auto slt = Solution();
    cout << slt.majorityElement(temp);
}
