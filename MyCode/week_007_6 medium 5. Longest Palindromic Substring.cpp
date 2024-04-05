// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
	string longestPalindrome(string s) {
		int left = 0;
		int right = 0;
		string max= s.substr(0,1);
		string temp;

		for (int current=0;current<s.size();)
		{
			left = right = current;

			// 좌우가 같은경우 센터가 2개인 팬드럼이다.
			if (left + 1 < s.length())
			{
				if (s.at(left) == s.at(left+1))
					right = current + 1;
			}

			while (left >= 0 && right < s.length())
			{
				if (s.at(left) == s.at(right))
				{
					temp = s.substr(left, right - left+1);
					if (max.length() < temp.length())
						max = temp;

					--left;
					++right;
				}
				else 
				{
					break;
				}
			}

			// 중앙이 하나인걸로 다시
			left = right = current;
			while (left >= 0 && right < s.length())
			{
				if (s.at(left) == s.at(right))
				{
					temp = s.substr(left, right - left + 1);
					if (max.length() < temp.length())
						max = temp;

					--left;
					++right;
				}
				else
				{
					break;
				}
			}
			

			++current;
		}

		return max;

	}
};