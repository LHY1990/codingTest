// https://leetcode.com/problems/valid-word/description/

class Solution {
public:
	set<char> vowelSet = set<char>({ 'a', 'e', 'i', 'o', 'u' });
	set<char> capitalVowelSet = set<char>({ 'A', 'E', 'I', 'O', 'U' });

	bool isValid(string word) {
		

		if (word.size() < 3)
			return false;

		int vowel = 0;
		int consonant = 0;
		
		for (const char& single : word)
		{
			//숫자인 경우
			if ('0' <= single && single <= '9')
			{
				continue;
			}
			else if ('a' <= single && single <= 'z') //소문자 거나
			{
				if (vowelSet.find(single) == vowelSet.end())
				{
					++consonant;
				}
				else {
					++vowel;
				}
				continue;
			}
			else if ('A' <= single && single <= 'Z') //대문자 거나
			{
				if (capitalVowelSet.find(single) == capitalVowelSet.end())
				{
					++consonant;
				}
				else {
					++vowel;
				}
				continue;
			}

			return false;
		}

		if (vowel == 0 || consonant == 0)
			return false;

		return true;
	}
};