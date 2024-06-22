// https://leetcode.com/problems/student-attendance-record-i/description/

class Solution {
public:
	bool checkRecord(string s) {
		int late = 0;
		int present = 0;
		int absent = 0;

		for (int i = 0;i < s.size();++i)
		{
			if (s.at(i) == 'A')
			{
				late = 0;
				++absent;
				if (absent >= 2)
					return false;
			}
			else  if (s.at(i) == 'L')
			{
				++late;
				if (late >= 3)
					return false;
			}
			else { // P
				late = 0;
			}
		}

		return true;
	}
};