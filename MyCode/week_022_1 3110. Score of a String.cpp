// https://leetcode.com/problems/score-of-a-string/description/

class Solution {
public:
	int scoreOfString(string s) {
		int sum = 0;
		for (int i = 0;i < s.length() - 1;++i)
		{
			sum += abs(s.at(i) - s.at(i + 1));
		}
		return sum;
	}
};