// https://leetcode.com/problems/permutation-difference-between-two-strings/description/

class Solution {
public:
	int findPermutationDifference(string s, string t) {
		if (s.size() <= 1)
			return 0;

		int count = 0;
		
		int tempInt;
		char tempChar;

		auto dict = map<char, int>();

		for (int i = 0;i < t.size();++i)
		{
			dict[t.at(i)] = i;
		}

		auto iter = map<char, int>::iterator();

		for (int left = 0;left < s.size();++left)
		{
			if (s.at(left) != t.at(left)) // 원본과 타겟이 다르면,
			{
				iter = dict.find(s.at(left));

				count += abs(iter->second - left);
        
			}
		}
		return count;
	}
};