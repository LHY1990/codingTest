// https://leetcode.com/problems/keyboard-row/submissions/1294346978/

class Solution {
public:
	set<char> row1 = set<char>({ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'});
	set<char> row2 = set<char>({ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'});
	set<char> row3 = set<char>({ 'z', 'x', 'c', 'v', 'b', 'n', 'm'});

	int getRow(char _char)
	{
		if (_char < 'a')
			_char = _char + 32;

		if (row1.find(_char) != row1.end())
			return 1;
		else if (row2.find(_char) != row2.end())
			return 2;
			
		return 3;
	}

	vector<string> findWords(vector<string>& words) {
		auto outList = vector<string>(0);

		char first;
		bool isInsert;

		for (const string single : words)
		{
			first = getRow(single.at(0));
			isInsert = true;
			for (int i = 1;i < single.size();++i)
			{
				if (first != getRow(single.at(i)))
				{
					isInsert = false;
					break;
				}
			}
			if (isInsert)
				outList.push_back(single);
		}

		return outList;
	}
};