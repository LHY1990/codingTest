// https://leetcode.com/problems/longest-continuous-increasing-subsequence/submissions/1306743375/

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.size();


		int maxSize = 0;
		int tempSize = 1;
		int term = 0;

		for (int i = 0; i < nums.size() - 1;++i)
		{
			term = nums.at(i + 1) - nums.at(i);
			
			if (term > 0)
				++tempSize;
			else
				tempSize = 1;
			

			if (maxSize < tempSize)
				maxSize = tempSize;
		}

		return maxSize;
	}
};