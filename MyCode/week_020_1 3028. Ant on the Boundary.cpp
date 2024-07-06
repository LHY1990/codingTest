// https://leetcode.com/problems/ant-on-the-boundary/description/

class Solution {
public:
	int returnToBoundaryCount(vector<int>& nums) {
		int pos = 0;
		int count = 0;
		for (const auto& single : nums)
		{
			pos += single;
			if (pos == 0)
				++count;
		}

		return count;
	}
};