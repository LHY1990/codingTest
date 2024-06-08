// https://leetcode.com/problems/guess-number-higher-or-lower/description/

class Solution {
public:
	int guessNumber(int n) {
		int returnCode = -10000;

		while (returnCode != 0)
		{
			returnCode = guess(n);

			if (returnCode == -1) //내가 고른게 높다면
			{
				n=n-n/2;
				
			}
			else if (returnCode == 1) //내가 고른게 낮다면
			{
				n += 1;
			}
			else if (returnCode == 0) //정답이면
			{
				return n;
			}
		}

		return n;
	}
};