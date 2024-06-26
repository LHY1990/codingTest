// https://leetcode.com/problems/add-digits/submissions/1275834410/

class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;

		int temp = 0;
		while (num!=0)
		{
			temp += num % 10;
			num /= 10;
		}

		return addDigits(temp);
	}
};