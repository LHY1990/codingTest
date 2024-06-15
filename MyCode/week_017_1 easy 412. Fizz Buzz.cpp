// https://leetcode.com/problems/fizz-buzz/description/

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		auto out = vector<string>(0);

		for (int i = 1;i <= n;++i)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				out.push_back("FizzBuzz");
				continue;
			}
			else if (i % 3 == 0)
			{
				out.push_back("Fizz");
				continue;
			}
			else if (i % 5 == 0)
			{
				out.push_back("Buzz");
				continue;
			}

			out.push_back(to_string(i));
		}

		return out;
	}
};