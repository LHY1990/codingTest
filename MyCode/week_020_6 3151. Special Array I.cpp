// https://leetcode.com/problems/special-array-i/description/

class Solution {
public:
	bool isArraySpecial(vector<int>& nums) {
		if (nums.size() == 1)
			return true;

		for (int left = 0;left < nums.size() - 1;++left)
		{
			if ((nums.at(left) + nums.at(left+1)) % 2 == 0)
				return false;
		}



		return true;
	}

};