// https://leetcode.com/problems/array-partition/submissions/1305328768/

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());

		int sum = 0;
		for (int i = 0;i < nums.size();++i)
		{
			if (i % 2 == 1)
				sum += nums.at(i);
		}
		return sum;
	}
};