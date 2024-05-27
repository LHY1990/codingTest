// https://leetcode.com/problems/move-zeroes/description/
    

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = 0;

		for (int i = 0;i < nums.size();)
		{
			if (nums.at(i) == 0)
			{
				nums.erase(nums.begin() + i);
				++count;
			}
			else
			{
				++i;
			}
		}

		for (int i = 0;i < count;++i)
		{
			nums.push_back(0);
		}
	}
};