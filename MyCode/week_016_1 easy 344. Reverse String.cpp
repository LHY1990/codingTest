// https://leetcode.com/problems/reverse-string/description/


class Solution {
public:
	void reverseString(vector<char>& s) {
		auto tempStack = stack<char>();
		for (int i = 0;i < s.size();++i)
		{
			tempStack.push(s.at(i));
		}
		s.clear();

		while(false == tempStack.empty())
        {
            s.push_back(tempStack.top());
            tempStack.pop();
        }
	}
};