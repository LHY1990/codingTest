// https://leetcode.com/problems/distribute-candies/description/

class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
        if (candyType.size()<=1)
            return candyType.size();

		auto kind = set<int>();

		for (int type : candyType)
		{
			if (kind.find(type) == kind.end())
			{
				kind.insert(type);
			}
		}

		auto kindCount = kind.size();// 종 종류 갯수
		auto maxEatable = candyType.size() / 2;

		return maxEatable > kindCount ? kindCount : maxEatable;

	}
};