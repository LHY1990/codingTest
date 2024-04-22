// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		set<int> checker = set<int>();
		for (int i = 0;i < nums.size();++i)
		{
			if (checker.end() != checker.find(nums.at(i)))
				return true;

			checker.insert(nums.at(i));
		}

		return false;
    }
};