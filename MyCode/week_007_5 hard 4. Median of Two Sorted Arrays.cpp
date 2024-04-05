// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int index1 = 0;
		int index2 = 0;
		vector<int> result = vector<int>(0);

		while (index1 < nums1.size() || index2 < nums2.size())
		{
			if (index1 < nums1.size() && index2 < nums2.size())
			{
				if (nums1.at(index1) < nums2.at(index2))
				{
					result.push_back(nums1.at(index1++));
				}
				else
				{
					result.push_back(nums2.at(index2++));
				}
			}
			else if (index1 >= nums1.size())
			{
				result.push_back(nums2.at(index2++));
			}
			else
			{
				result.push_back(nums1.at(index1++));
			}
		}

		int half = result.size() / 2;
		if (result.size() % 2 == 0) // even
		{
			return (result.at(half - 1) + result.at(half)) / 2.0;
		}
		
		return result.at(half);
	}
};