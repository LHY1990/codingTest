// https://leetcode.com/problems/nim-game/description/

class Solution {
public:
	bool canWinNim(int n) {
		if (n <= 3)
			return true;

		if (n % 4 == 0)
			return false;
		else
			return true;
	}
};