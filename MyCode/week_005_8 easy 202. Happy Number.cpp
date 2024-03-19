// https://leetcode.com/problems/happy-number/submissions/1208025429/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	vector<int> checker = vector<int>(0);

	bool isHappy(int n) {
		if (n == 1)
			return true;

		// if exist before
		if (find(checker.begin(), checker.end(), n) != checker.end())
			return false;

		checker.push_back(n);


		int current = 0;
		vector<int> sum = vector<int>(0);

		while (n!=0)
		{
			current = n % 10;
			sum.push_back(current*current);
			n = n / 10;
		}

		int result = 0;
		for (const auto& single : sum)
			result += single;

		sum.clear();
		return isHappy(result);
	}
};