// https://leetcode.com/problems/valid-perfect-square/description/

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num == 0 || num == 1)
			return true;

		unsigned long long temp = 1;

		while (temp * temp < num)
		{
			++temp;

			if (num % temp != 0)
				continue;

			if (temp * temp == num)
				return true;
		}
		
		return false;
	}
};