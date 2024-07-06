// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		int out = 0;
		int temp = 0;

		for (const auto& single : nums)
		{
			temp = single % 3;
			if (temp == 0)
			{
			}
			else if (temp == 1)
			{
				++out;
			}
			else if (temp == 2)
			{
				++out;
			}

		}

		return out;
	}
};