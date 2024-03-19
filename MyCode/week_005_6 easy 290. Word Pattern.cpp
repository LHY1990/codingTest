// https://leetcode.com/problems/word-pattern/submissions/1208006068/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	bool wordPattern(string pattern, string s) {

		if (s.at(0) == ' ')
			return false;

		int offset = 0;
		int end = 0;
		vector<string> list = vector<string>(0);

		for (; end < s.length();++end)
		{
			if (s.at(end) != ' ')
				continue;

			list.push_back(s.substr(offset, end - offset));

			offset = end + 1;
		}

		if (offset != end)
			list.push_back(s.substr(offset, end - offset));

		if (pattern.length() != list.size())
			return false;

		map<char, string> checker = map<char, string>();
		vector<string> checkDupList = vector<string>(0);
		map<char, string>::iterator iter;
		
		char target;
		for (int i=0;i<pattern.size();i++)
		{
			target = pattern.at(i);

			iter = checker.find(target);
			if (iter == checker.end()) {
				//check duplicate
				if (find(checkDupList.begin(), checkDupList.end(), list.at(i)) != checkDupList.end())
					return false;

				checkDupList.push_back(list.at(i));

				checker[target] = list.at(i);
				continue;
			}

			if (iter->second.compare(list.at(i)) != 0)
				return false;
		}

		return true;

	}
};