// https://leetcode.com/problems/split-the-array/description/

class Solution {
public:
	bool isPossibleToSplit(vector<int>& nums) {
		auto checker = map<int, int>();
		auto iter = map<int, int>::iterator();

		for (const int& single : nums)
		{
			iter = checker.find(single);
			if (iter == checker.end()) //없으면 넣어준다
			{
				checker[single] = 1;
			}
			else
			{
				if (iter->second >= 2)
					return false;

				iter->second += 1;
			}
		}

		return true;
	}
};