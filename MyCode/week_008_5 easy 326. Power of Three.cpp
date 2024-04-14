// https://leetcode.com/problems/power-of-three/description/

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 1)
			return true;
		else if (n == 0)
			return false;
		else if (n > 0 && (n % 3) > 0)
			return false;

		int temp = n / 3;
		if (temp * 3 != n)
			return false;

		return isPowerOfThree(temp);
	}
};