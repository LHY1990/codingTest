// https://leetcode.com/problems/first-bad-version/submissions/1275889650/

class Solution {
public:
	int firstBadVersion(int n) {
		int before = 1;
		for (int i = 1;i <= n;i++)
		{
            before = i;
			if (isBadVersion(i) == true)
			{
				break;
			}
		}

		return before;
	}
};