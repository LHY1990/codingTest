// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/

class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		int count = 0;
		for (const int& single : nums)
		{
			if (single < k)
				++count;
		}

		return count;
	}
};