// https://leetcode.com/problems/intersection-of-two-arrays/description/

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		auto left = set<int>(nums1.begin(), nums1.end());
		auto right = set<int>(nums2.begin(), nums2.end());

		auto leftList = vector<int>(left.begin(), left.end());
		auto rightList = vector<int>(right.begin(), right.end());

		sort(leftList.begin(), leftList.end());
		sort(rightList.begin(), rightList.end());

		auto outList = set<int>();

		int leftIter = 0;
		int rightIter = 0;
		while (leftIter < leftList.size() && rightIter < rightList.size())
		{
			if (leftList.at(leftIter) == rightList.at(rightIter))
			{
				outList.insert(leftList.at(leftIter));
				++leftIter;
				++rightIter;
			}
			else if (leftList.at(leftIter) < rightList.at(rightIter))
			{
				++leftIter;
			}
			else
			{
				++rightIter;
			}
		}

		return vector<int>(outList.begin(), outList.end());
	}
};