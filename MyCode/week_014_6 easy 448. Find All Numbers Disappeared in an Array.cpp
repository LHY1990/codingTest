//  https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int size = nums.size();
		auto filterSet = set<int>(nums.begin(), nums.end());

		auto resultVector = vector<int>(0);
		
		for (int i = 1;i <= nums.size();++i)
		{
			if (filterSet.find(i) == filterSet.end())
			{
				resultVector.push_back(i);
			}
		}

		return resultVector;

	}
};