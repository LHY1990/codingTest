// https://leetcode.com/problems/missing-number/submissions/1262888505/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		auto checker = set<int>();
		for (const auto& single : nums)
		{
			checker.insert(single);
		}

		for (int i = 0;i < nums.size();++i)
		{
			if (checker.find(i) == checker.end())
				return i;
		}

		return nums.size();
	}
};