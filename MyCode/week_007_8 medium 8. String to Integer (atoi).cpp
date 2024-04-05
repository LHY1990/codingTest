// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
private:
	bool isNumber(char param) 
	{
		return '0' <= param && param <= '9';
	}

	bool isChar(char param)
	{
		return param < '0' || param > '9';
	}

public:
	int myAtoi(string s) {
		vector<char> filter=vector<char>(0);
		vector<char> noise = vector<char>(0);
		char current;
		int minusCount = 0;
		int plusCount = 0;

		for (int i = 0; i < s.length();++i )
		{
			current = s.at(i);
			if (minusCount + plusCount >= 2)
				break;

			if (plusCount && current == ' ')
				break;

			if (current == ' ' && filter.size()==0)
				continue;

			if (current == ' ')
				break;

			if (filter.size() == 0 && current == '-')
			{
				++minusCount;
				continue;
			}

			if (filter.size() == 0 && current == '+')
			{
				++plusCount;
				continue;
			}

			if (current == '.')
				break;

			// 첫 글자가 문자
			if (isChar(current) && filter.size() == 0)
				break;

			if (isChar(current))
			{
				noise.push_back(current);
				continue;
			}

			if (noise.size() > 0)
				continue;

			filter.push_back(current);
		}

		if (plusCount && minusCount)
			return 0;

		if (filter.size() == 0)
			return 0;

		double result = 0;
		for (int i=0;i < filter.size();++i)
		{
			result += pow(10, filter.size()-1-i) * (filter.at(i) - '0');
		}

		if (minusCount)
			result = -result;

		if (result >= INT_MAX)
			return INT_MAX;
		else if (result <= INT_MIN)
			return INT_MIN;


		return static_cast<int>(result);

	}
};