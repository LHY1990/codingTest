// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
	double myPow(double x, int n) {


		if (x == 0)
			return 0;
		if (n == 0)
			return 1;
		if (x == 1)
			return 1;
		if (x == -1)
		{
			if (n % 2 == 1)
				return -1;
			else
				return 1;
		}

		
		double temp = 0;
		int64_t uintN = n;

        if (uintN < 0 && -uintN >= 19)
			return 0;


		if (uintN > 0)
		{
			temp = x;
			for (int64_t i = 1;i < uintN;++i)
			{
				temp *= x;
			}
		}
		else
		{
			uintN = uintN * -1;
			temp = x;
			for (int64_t i = 0;i < uintN;++i)
			{
				temp *= x;
			}

			temp = x / temp;
		}

		return temp;
	}
};