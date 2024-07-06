// https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/

class Solution {
public:
	int numberOfChild(int n, int k) {
		const int LEFT = 0;
		const int RIGHT = 1;
		
		int current = 0;
		int direction = RIGHT;

        if (k > (n * 2 - 2))
		{
			k = k % (n * 2 - 2);
		}

		for (int i = 0;i < k;++i)
		{
			if (direction == RIGHT)
			{
				if (current + 1 < n)
				{
					++current;
				}
				else
				{
					direction = LEFT;
					--current;
				}
			}
			else
			{
				if (current > 0)
				{
					--current;
				}
				else
				{
					direction = RIGHT;
					++current;
				}
			}
            cout << current <<endl;
		}

		return current;
	}
};