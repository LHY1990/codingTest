// https://leetcode.com/problems/power-of-four/submissions/1230107008/

class Solution {
public:
	bool isPowerOfFour(int n) {
		if (n == 1)
			return true;
		else if (n == 0)
			return false;
		else if (n > 4 && n % 4 == 1)
			return false;
		
		int temp = n / 4;
		if (n != temp * 4)
			return false;

		return isPowerOfFour(temp);
	}
};