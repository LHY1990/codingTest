// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
	string makeString(vector<int>::iterator _begin, vector<int>::iterator _end)
	{
		string out = "";
		int checker = 0;
		for (auto iter = _begin;iter != _end;++iter)
		{
			if (*iter == 1) //1이면 (
			{
				++checker;
				out += "(";
			}
			else { // 0이면 )
				--checker;
				out += ")";
			}

			if (checker < 0)
				return "";
		}

		return out;
	}

	vector<string> generateParenthesis(int n) {
		set<string> out = set<string>();
		vector<int> codeList = vector<int>(0);
		string result;



		for (int i = 1;i <= n*2;++i)
			codeList.push_back(i%2);

		do {

			if (codeList.at(0) == 0)
				continue;
		

			result = makeString(codeList.begin(), codeList.end());
			if (false == result.empty())
				out.insert(result);

		} while (next_permutation(codeList.begin(), codeList.end()));

		return vector<string>(out.begin(), out.end());

	}
};