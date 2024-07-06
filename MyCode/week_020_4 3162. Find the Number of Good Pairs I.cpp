// https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/

class Solution {
public:
	int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int count = 0;


		for (int& right : nums2)
		{
			right *= k;
			for (const auto& left : nums1)
			{
				if (left < right)
					continue;

				if (left % right == 0)
				{
					++count;
				}
			}
		}

		return count;
	}
};