// https://leetcode.com/problems/plus-one/description/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return digits;

		vector<int> out = vector<int>(0);

		int current = 0;
		for (int i = digits.size() - 1;i >= 0;--i)
		{
			current += digits.at(i);
			if (i == digits.size() - 1)
				++current;

			digits.at(i) = current % 10;

			current = current / 10;

			if (i == 0)
			{
				if (current != 0)
				{
					out.push_back(current);
					out.insert(out.begin() + 1, digits.begin(), digits.end());
				}
				else
				{
					out = digits;
				}
			}

		}

		return out;

	}
};