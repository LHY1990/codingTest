// https://leetcode.com/problems/add-binary/submissions/1234629589/

class Solution {
public:
	string addBinary(string a, string b) {
		int max = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int count = 0;
		if (a.size() < max)
		{
			count = max - a.size();
			for (int i = 0;i < count;++i)
				a.push_back('0');
		}
		else if (b.size() < max)
		{
			count = max - b.size();
			for (int i = 0;i < count;++i)
				b.push_back('0');
		}

		int temp=0;
		string out = "";
		for (int i = 0;i < max;++i)
		{
			temp += a.at(i) - '0';
			temp += b.at(i) - '0';

			if (temp == 0)
			{
				out.push_back('0');
			}
			else if (temp == 1)
			{
				out.push_back('1');
				temp = 0;
			}
			else if (temp == 2)
			{
				out.push_back('0');
				temp = temp / 2;
			}
			else if (temp == 3)
			{
				out.push_back('1');
				temp = 1;
			}
		}

		if (temp == 1)
			out.push_back('1');

		reverse(out.begin(), out.end());

		return out;
	}
};