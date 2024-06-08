// https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/1276025672/


class Solution {
public:
	bool isVowel(const char& _char)
	{
		switch (_char)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;
		default:
			return false;
		}
	}

	string reverseVowels(string s) {
		if (s.empty())
			return s;

		auto vowelStack = stack<char>();
		auto memory = vector<int>(0);

		for (int i = 0;i < s.size();++i)
		{
			if (isVowel(s.at(i)))
			{
				memory.push_back(i);
				vowelStack.push(s.at(i));
			}
		}

		if (vowelStack.empty())
			return s;

		string out;
		for (int i = 0;i < s.size();++i)
		{
			//해당 위치라면
			if (memory.front() == i)
			{
				out += vowelStack.top();
				vowelStack.pop();
				memory.erase(memory.begin());
			}
			else {
				out += s.at(i);
			}
		}

		return out;
	}
};