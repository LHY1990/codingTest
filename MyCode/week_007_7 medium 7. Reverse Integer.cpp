// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
	int reverse(int x) {
		bool isPos = x > 0 ? true : false;

		long input = x;
		if (false == isPos)
			input = -input;

		long longResult=0;
		
		string number = to_string(input);
		for (int i = number.size() - 1;i >= 0;--i)
		{
			longResult += pow(10, i) * (number.at(i) - '0');
		}

		if (false == isPos)
			longResult = -longResult;

		int intResult = longResult;

		if (intResult != longResult)
			return 0;
		
		return intResult;
	}
};