// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/

class Solution {
public:
	int countCompleteDayPairs(vector<int>& hours) {
		int count = 0;
		int temp = 0;

		for (int left = 0;left < hours.size();++left)
		{
			temp = 0;

			for (int right = left + 1;right < hours.size();++right)
			{
				if ((hours.at(left) + hours.at(right)) % 24 == 0)
				{
					++count;
				}
			}
		}
			

		return count;
	}
};