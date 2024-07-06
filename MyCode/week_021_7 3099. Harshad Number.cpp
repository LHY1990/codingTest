// https://leetcode.com/problems/harshad-number/submissions/1308890553/

class Solution {
public:
	int sumOfTheDigitsOfHarshadNumber(int x) {
		int sum = x == 100 ? 1 : -1;
		if (sum == -1)
		{
			sum = x % 10 + x / 10;
		}

		if (x % sum == 0)
			return sum;

		return -1;
	}
};