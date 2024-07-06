// https://leetcode.com/problems/type-of-triangle/description/

class Solution {
public:
	string triangleType(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // 오름차순

		if ((nums.at(0) + nums.at(1)) <= nums.at(2))
			return "none";

		if ((nums.at(0) == nums.at(1)) && nums.at(1) == nums.at(2))
			return "equilateral";
		else if (nums.at(0) == nums.at(1) || nums.at(1) == nums.at(2))
			return "isosceles";
		
		return "scalene";
	}
};