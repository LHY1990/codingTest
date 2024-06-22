// https://leetcode.com/problems/max-consecutive-ones/description/


class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		int out = 0;
		int current = 0;

		for (auto single : nums)
		{
			if (single == 1)
			{
				++current;
				if (out < current)
				{
					out = current;
				}
			}
			else
			{
				current = 0;
			}
		}

		return out;
	}
};