// https://leetcode.com/problems/number-complement/description/

class Solution {
public:
	int findComplement(int num) {
		if (num == 0)
			return 0;

		bitset<32> bs(num);

		string bitString = bs.to_string();
		int first = -1;
		string result;

		for (int i = 0; i < bitString.size(); ++i)
		{
			if (first < 0 && bitString.at(i) == '1')
				first = i;

			if (first >= 0)
			{
				if (bitString.at(i) == '1')
					result += '0';
				else
					result += '1';
			}
		}

		reverse(result.begin(), result.end());

		int out = 0;
		for (int i = 0; i < result.size(); ++i)
		{
			if (result.at(i)=='1')
				out += pow(2, i);
		}

		return out;

	}
};