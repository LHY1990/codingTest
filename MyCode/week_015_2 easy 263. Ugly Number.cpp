// https://leetcode.com/problems/ugly-number/submissions/1275842918/

class Solution {
public:
	bool isUgly(int n) {
		if (n == 2 || n == 3 || n == 5)
			return true;

		if (n == 0)
			return false;
		
		if (n % 2 == 0)
		{
			return isUgly(n / 2);
		}
		else if (n % 3 == 0)
		{
			return isUgly(n / 3);
		}
		else if (n % 5 == 0)
		{
			return isUgly(n / 5);
		}

		if (n == 1)
			return true;

		return false;

	}
};