// https://leetcode.com/problems/find-the-integer-added-to-array-i/submissions/1309050155/

class Solution {
public:
	int addedInteger(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 1)
			return nums2.at(0) - nums1.at(0);

		int min1 = 1000;
		int min2 = 1000;

		for (int i = 0;i < nums1.size();++i)
		{
			if (min1 == 0 && min2 == 0)
				return 0;

			if (min1 != 0 && nums1.at(i) < min1)
				min1 = nums1.at(i);
			if (min2 != 0 && nums2.at(i) < min2)
				min2 = nums2.at(i);
		}

		return min2 - min1;
	}
};