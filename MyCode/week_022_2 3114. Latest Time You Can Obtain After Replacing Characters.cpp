// https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/description/


class Solution {
public:
	string findLatestTime(string s) {
		if (s.at(0) == '?')
		{
			if (s.at(1) != '?' && s.at(1) > '1')
				s.at(0) = '0';
			else
				s.at(0) = '1';
		}
		if (s.at(1) == '?')
		{
			if (s.at(0) == '1')
				s.at(1) = '1';
			else
				s.at(1) = '9';
		}
		if (s.at(3) == '?')
			s.at(3) = '5';
		if (s.at(4) == '?')
			s.at(4) = '9';

		return s;
	}
};