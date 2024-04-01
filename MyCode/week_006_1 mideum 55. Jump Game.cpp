#include<string>
#include<iostream>
#include<vector>
#include<set>

// https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==1)
            return true;
        else if (nums.at(0) == 0 && nums.size() > 1)
            return false;

        int max = 0;
        int move = nums.at(0);

        for (int current = 0; current < nums.size(); current++) // -1
        {
            max = 0;
            move = move > (nums.size()-1) ? nums.size()-1 : move;

            for (int i = current; i <= move; i++)
            {
                if (max < nums.at(i)+i)
                {
                    max = nums.at(i)+i;
                    current = i;
                }

                if (max >= nums.size()-1)
                    return true;
            }

            move = max;
        }

        cout << endl;

        return false;
    }
};

void main()
{
    auto p1 = vector<int>{ 1,1,2,2,0,1,1 };
    Solution slt = Solution();
    bool result = slt.canJump(p1);
    cout <<"result" << result;

    return;
}