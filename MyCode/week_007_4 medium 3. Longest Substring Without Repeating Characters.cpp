// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1)
			return s.length();

		set<char> list = set<char>();
		set<char> ::iterator iter;
		int max = 0;
		int current = 0;

		for (int current = 0;current < s.length() - 1;++current)
		{
			for (int i = current;i < s.length();++i)
			{
				iter = list.find(s.at(i));
				if (iter == list.end())
				{
					list.insert(s.at(i));

					if (max < list.size())
						max = list.size();
				}
				else {
					list.clear();
					break;
				}
			}
		}

		return max;
	}
};