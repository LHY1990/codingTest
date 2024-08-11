// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = -1;
		int right = -1;
		
		for (int i = 0;i < nums.size();++i)
		{
			if (nums.at(i) == target && left == -1)
			{
				left = i;
				break;
			}
		}

		if (left == -1)
			return vector<int>({ -1, -1 });

		for (int i = nums.size() - 1;i >= left;--i)
		{
			if (nums.at(i) == target)
			{
				right = i;
				return vector<int>({ left, right });
			}
		}

		return vector<int>({ -1, -1 });
	}
};