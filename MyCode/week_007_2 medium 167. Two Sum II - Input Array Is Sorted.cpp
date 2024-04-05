// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		int sum = 0;
		while (left != right)
		{
			sum = numbers.at(left) + numbers.at(right);
			if (sum == target)
				return vector<int>{++left, ++right};
			else if (sum < target)
				++left;
			else
				--right;
		}

        return vector<int>{++left, ++right};
	}
};