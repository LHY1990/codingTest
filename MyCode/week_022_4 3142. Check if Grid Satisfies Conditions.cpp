// https://leetcode.com/problems/check-if-grid-satisfies-conditions/description/

class Solution {
public:
	bool satisfiesConditions(vector<vector<int>>& grid) {
		int preNum = grid.at(0).at(0);
		for (int i=1;i<grid.at(0).size();++i)
		{
			if (preNum == grid.at(0).at(i))
				return false;

			preNum = grid.at(0).at(i);
		}

		for (int i = 1;i < grid.size();++i)
		{
			for (int inner = 0;inner < grid.at(0).size();++inner)
			{
				if (grid.at(0).at(inner) != grid.at(i).at(inner))
					return false;
			}
		}

		return true;
	}
};