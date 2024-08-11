// https://leetcode.com/problems/find-the-sum-of-encrypted-integers/description/

class Solution {
public:
	int sumOfEncryptedInt(vector<int>& nums) {
		int out = 0;
		int ten;
		int one;
		int hundred;
		int big;

		for (const auto& single : nums)
		{
			if (single < 10)
			{
				out += single;
			}
			else if (single >= 10 && single < 100)
			{
				one = single % 10;
				ten = single / 10;

				big = one > ten ? one : ten;
				out += big * 10 + big;
			}
			else if (single >= 100 && single < 1000)
			{
				one = single % 10;
				ten = (single %100) / 10;
				hundred = single / 100;

				big = one > ten ? one : ten;
				big = big > hundred ? big : hundred;

				out += big * 100 + big * 10 + big;

			}
			else if (single == 1000)
			{
				out += 1111;
			}
		}


		return out;
	}
};