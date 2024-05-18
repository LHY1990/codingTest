// https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		bitset<32> bitset{n };

		auto str = bitset.to_string();

		uint32_t result = 0;
		for (int i = 0; i < 32; ++i)
		{
			if (str.at(i) == '1')
			{
				result += pow(2, i);
			}
		}

		return result;
	}
};
