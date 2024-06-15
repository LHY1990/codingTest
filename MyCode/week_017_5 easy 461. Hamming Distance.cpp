// https://leetcode.com/problems/hamming-distance/description/

class Solution {
public:
	int hammingDistance(int x, int y) {
		if (x == y)
			return 0;

		int result = x ^ y;
		bitset<32> bitsetStr(result);

		const string target = bitsetStr.to_string();
		int out = 0;
		
		for (int i = 0; i< target.size(); ++i)
		{
			if (target.at(i) == '1')
				++out;
		}

		return out;
	}
};