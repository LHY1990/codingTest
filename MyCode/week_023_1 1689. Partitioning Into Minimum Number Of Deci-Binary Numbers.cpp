// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

class Solution {
public:
	int minPartitions(string n) {
		int max = 0;
		int temp = 0;
		for (int i = 0;i < n.size();++i)
		{
			temp = n.at(i) - '0';
			if (temp == 9)
				return 9;

			if (max < temp)
				max = temp;
		}

		return max;
	}
};