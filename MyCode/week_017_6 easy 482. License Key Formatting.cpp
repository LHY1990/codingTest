// https://leetcode.com/problems/license-key-formatting/description/


class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string temp;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s.at(i) != '-')
			{
				if ('a' <= s.at(i) && s.at(i) <='z')
				{
					temp += s.at(i) - 32;
				}
				else 
				{
					temp+=s.at(i);
				}

			}
		}

		if (temp.size() <= k)
		{
			return temp;
		}
		else 
		{
			int firstSize = temp.size() % k;
			string result;

			if (firstSize!=0)
			{
				for (int i = 0; i < firstSize; ++i)
				{
					result += temp.at(i);
				}

				result += '-';
			}

			int tempIndex = 1;
			for (int i = firstSize; i < temp.size(); ++i)
			{
				result += temp.at(i);

				if (tempIndex++ % k == 0 && i+1 != temp.size())
				{
					result += '-';
				}
			}

			return result;
		}
	}
};