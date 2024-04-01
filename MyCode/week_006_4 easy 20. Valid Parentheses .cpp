// https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:

	bool isValid(string s) {
		stack<char> charStack = stack<char>();



		for (int i = 0;i < s.length();i++)
		{
			switch (s.at(i))
			{
			case '(':
			case '[':
			case '{':
			{
				charStack.push(s.at(i));
				continue;
			}
			case ')':
			{
				if (charStack.empty() || charStack.top() != '(')
					return false;

				charStack.pop();

				continue;
			}
			case ']':
			{
				if (charStack.empty() || charStack.top() != '[')
					return false;

				charStack.pop();

				continue;
			}
			case '}':
			{
				if (charStack.empty() || charStack.top() != '{')
					return false;

				charStack.pop();

				continue;
			}
			}
		}
		if (charStack.size() != 0)
			return false;

		return true;
	}
};