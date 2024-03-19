// https://leetcode.com/problems/valid-anagram/submissions/1208008774/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())
			return false;

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		for (int i = 0;i < s.length();i++)
		{
			if (s.at(i) != t.at(i))
				return false;
		}

		return true;
	}
};