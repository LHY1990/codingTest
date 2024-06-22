// https://leetcode.com/problems/detect-capital/description/

class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.size() <= 1)
			return true;

		if (word.size() == 2)
		{
			// 두 글자에서 첫자리가 소문자인데 둘째가 대문자면 false, 기타는 true
			if (word.at(0) >= 'a' && word.at(1) <= 'Z')
				return false;
			else
				return true;
		}

		if (word.at(0) >= 'a') //첫글자가 소문자면 하나라도 대문자면 false
		{
			for (int i = 1;i < word.size();++i)
			{
				if (word.at(i) <= 'Z')
					return false;
			}
			return true;
		}
		else { //첫 글자가 대문자면, 
			if (word.at(1) <= 'Z') //두번째 글자도 대문자면 모두 대문자 여야하고, 
			{
				for (int i = 2;i < word.size();++i)
				{
					if (word.at(i) >= 'a')
						return false;
				}
				return true;
			}
			else // 아니면 모두 소문자여야한다.
			{
				for (int i = 2;i < word.size();++i)
				{
					if (word.at(i) <= 'Z')
						return false;
				}
				return true;
			}

		}


		cout << "모든 조건을 피함";

		return false;
	}
};