#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() <= 1)
            return 0;
        
        int max{ 0 };
        int value{ 0 };

        for (int postIndex = prices.size() - 1; postIndex >= 0; postIndex--)
        {
            if (prices.at(postIndex) <= max)
                continue;

            for (int preIndex = 0; preIndex < postIndex; preIndex++)
            {

                value = prices.at(postIndex) - prices.at(preIndex);
                if (value > max)
                    max = value;
            }
        }
        

        return max;
    }
};

void main()
{
    vector<int> temp{ 7,1,5,3,6,4 };
    auto slt = Solution();

    auto result = slt.maxProfit(temp);
    cout << result << endl;


}