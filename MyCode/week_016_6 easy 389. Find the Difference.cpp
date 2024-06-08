// https://leetcode.com/problems/find-the-difference/submissions/1276120097/

class Solution {
public:
	char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		for (int i = 0;i < s.size();++i)
		{
			if (s.at(i) != t.at(i)) {
				return t.at(i);
			}
		}

		return t.at(t.size() - 1);
	}
};