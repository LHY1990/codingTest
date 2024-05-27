// https://leetcode.com/problems/assign-cookies/description/

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int result = 0;
		int sizeIndex = 0;

		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		for (int i=0;i<g.size();)
		{
			if (sizeIndex >= s.size())
				return result;

			if (g.at(i) > s.at(sizeIndex))
			{
				++sizeIndex;
				continue;
			}

			++i;
			++result;
			++sizeIndex;
		}

		return result;
	}
};