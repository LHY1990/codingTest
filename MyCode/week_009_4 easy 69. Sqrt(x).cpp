// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
	int mySqrt(int x) {
        if (x <= 1)
			return x;

		uint64_t current = x;
		uint64_t temp=0;

		uint64_t before=0;
		while (true)
		{
			temp = current * current;
			if (temp < x)
				break;

			before = current;
			current = current / 2;
		}

		current = before;

		while (true)
		{
			temp = current * current;
			if (temp < x)
			{
				return current;
			}
			else if (temp == x)
			{
				return current;
			}
			
			--current;
		}

		return current;
	}
};