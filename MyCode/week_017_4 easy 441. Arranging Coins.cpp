// https://leetcode.com/problems/arranging-coins/description/

class Solution {
public:
	int arrangeCoins(int n) {
		if (n <= 0)
			return 0;

		int current = 1;
		while (current <= n)
		{
			n = n - current;
			++current;
		}

		return current - 1;
	}
};