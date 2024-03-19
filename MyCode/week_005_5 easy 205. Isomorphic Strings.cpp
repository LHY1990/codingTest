// https://leetcode.com/problems/isomorphic-strings/submissions/1207954597/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, int> sMap = map<char, int>();
		map<char, int> tMap = map<char, int>();
		map<char, int>::iterator iter;

		int index = 1;
		for (auto single : s)
		{
			iter = sMap.find(single);
			if (iter == sMap.end())
				sMap[single] = index++;
		}

		index = 1;
		for (auto single : t)
		{
			iter = tMap.find(single);
			if (iter == tMap.end())
				tMap[single] = index++;
		}

		for (int i=0;i<s.length();++i)
		{
			if (sMap.find(s.at(i))->second != tMap.find(t.at(i))->second)
				return false;
		}

		return true;

	}
};