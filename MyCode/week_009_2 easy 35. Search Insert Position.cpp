// https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		for (int i = 0;i < nums.size();++i)
		{
			if (nums.at(i) < target)
			{
				continue;
			}
			else if (nums.at(i) >= target)
			{
				return i;
			}
			
		}

		return nums.size();
	}
};