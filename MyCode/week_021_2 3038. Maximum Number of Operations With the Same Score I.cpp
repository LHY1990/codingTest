// https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/description/

class Solution {
public:
	int maxOperations(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		else if (nums.size() == 2)
			return 1;
		
		int firstSum = nums.at(0)+nums.at(1);
		int count = 1;

		for (int i = 2;i < nums.size() - 1;i+=2)
		{
			if (i + 1 >= nums.size())
				break;         

			if ((nums.at(i) + nums.at(i + 1)) == firstSum)
				++count;
            else
                break;
		}

		return  count;

	}
};