// https://leetcode.com/problems/perfect-number/description/

class Solution {
public:
	bool checkPerfectNumber(int num) {

		auto half = num / 2;
		int temp = 0;

		for (int i = 1;i < num;++i)
		{
			if (num % i == 0)
				temp += i;

			if (temp > num)
				return false;
		}

		if (temp == num)
			return true;


		return false;
	}
};