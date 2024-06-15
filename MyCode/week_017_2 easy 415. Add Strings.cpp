// https://leetcode.com/problems/add-strings/description/

class Solution {
public:
	void addZero(string& _input, const int& _size)
	{
		string temp;
		for (int i = 0;i < _size; ++i)
		{
			temp += '0';
		}

		_input = temp + _input;
	}

	string addStrings(string num1, string num2) {
		string out;
		int index = 0;

		int maxLength = num1.size() > num2.size() ? num1.size() : num2.size();

		if (num1.size() < maxLength) //첫번째가 부족하면 0으로 메꿔준다
		{
			addZero(num1, maxLength-num1.size());
		}
		else if (num2.size() < maxLength)
		{
			addZero(num2, maxLength-num2.size());
		}

		bool hasNext = false;
		int temp = 0;
		for (int i = maxLength-1;i >= 0;--i)
		{
			temp = hasNext ? 1 : 0;
			hasNext = false;
			temp = num1.at(i) - '0' + num2.at(i) - '0' + temp;
			if (temp >= 10)
			{
				hasNext = true;
				temp = temp % 10;
			}

			out = static_cast<char>(temp+'0') + out;
		}

		if (hasNext)
			out = '1' + out;

		return out;
	}
};