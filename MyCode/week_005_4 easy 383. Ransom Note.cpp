// https://leetcode.com/problems/ransom-note/submissions/1207941348/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.length() > magazine.length())
			return false;

		map<char, int> rMap = map<char, int>();
		map<char, int> mMap = map<char, int>();

		map<char, int>::iterator iter;

		for (auto single : ransomNote)
		{
			iter = rMap.find(single);
			if (iter == rMap.end())
				rMap[single] = 1;
			else
				iter->second++;
		}

		for (auto single : magazine)
		{
			iter = mMap.find(single);
			if (iter == mMap.end())
				mMap[single] = 1;
			else
				iter->second++;
		}

		for (auto single : rMap)
		{
			iter = mMap.find(single.first);
			if (iter == mMap.end())
				return false;

			if (iter->second < single.second)
				return false;
		}

		return true;
	}
};