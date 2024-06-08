// https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
	int countBin(int _input)
	{
		int result = 0;

		while (_input >= 1)
		{
			if (_input % 2 == 1)
				++result;

			_input = _input >> 1;
		}

		return result;
	}

	vector<int> countBits(int n) {
		auto result = vector<int>(0);

		for (int i = 0;i <= n;++i)
		{
			result.push_back(countBin(i));
		}

		return result;
	}
};