// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1263752041/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;

		if (nums.size() == 1)
		{
			if (nums.at(0) == target)
				return 0;
			else
				return -1;
		}

		int front = nums.at(0);
		int end = nums.at(nums.size() - 1);

		int frondDiff = abs(target - front);
		int endDiff = abs(target - end);

		if (frondDiff > endDiff)//앞 차이가 크다는건 뒤에서 시작하라는것, 뒤에서 시작한다는건 내림차순이라는것
		{
			for (int i = nums.size() - 1;i >= 0;--i)
			{
				if (target > nums.at(i))
					return -1;

				if (target == nums.at(i))
					return i;
			}
		}
		else
		{
			for (int i = 0;i < nums.size();++i)
			{
				if (target < nums.at(i))
					return -1;

				if (target == nums.at(i))
					return i;
			}
		}

		return -1;
	}
};