// https://leetcode.com/problems/power-of-two/submissions/1230106108/

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 1)
			return true;
		else if (n == 0)
			return false;
		else if (n > 2 && n % 2 == 1)
			return false;
		
		int temp = n / 2;
		if (n != temp * 2)
			return false;

		return isPowerOfTwo(temp);
	}
};