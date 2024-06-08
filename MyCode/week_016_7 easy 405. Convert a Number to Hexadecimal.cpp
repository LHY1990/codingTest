// https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/

class Solution {
public:
	vector<char> hexList = vector<char>({ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'});
	const int HEX = 16;

	string toHex(int num) 
	{
		if (num == 0)
			return "0";

		unsigned int input = num;
		string out;
		int temp = 0;

		if (num < 0)
			input = UINT32_MAX + num + 1;

		while (input > 0)
		{
			temp = input % HEX;
			out += hexList.at(temp);
			input /= HEX;
		}

		reverse(out.begin(), out.end());
		return out;
	}
};