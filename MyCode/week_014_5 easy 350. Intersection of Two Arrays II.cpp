// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		auto outList = vector<int>(0);

		int leftIter = 0;
		int rightIter = 0;
		while (leftIter < nums1.size() && rightIter < nums2.size())
		{
			if (nums1.at(leftIter) == nums2.at(rightIter))
			{
				outList.push_back(nums1.at(leftIter));
				++leftIter;
				++rightIter;
			}
			else if (nums1.at(leftIter) < nums2.at(rightIter))
			{
				++leftIter;
			}
			else
			{
				++rightIter;
			}
		}

		return outList;
	}
};