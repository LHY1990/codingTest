// https://leetcode.com/problems/make-a-square-with-the-same-color/description/

class Solution {
public:
	bool canMakeSquare(vector<vector<char>>& grid) {
		int B;
		int W;
		for (int h = 0;h < 2; ++h)
		{

			for (int w = 0;w < 2;++w)
			{
				W = 0;
				B = 0;

				grid.at(h).at(w) == 'W' ? ++W : ++B;
				grid.at(h).at(w+1) == 'W' ? ++W : ++B;
				grid.at(h+1).at(w) == 'W' ? ++W : ++B;
				grid.at(h+1).at(w+1) == 'W' ? ++W : ++B;

				if (W >= 3)
					return true;
				else if (B >= 3)
					return true;
			}
		}

		return false;
	}
};