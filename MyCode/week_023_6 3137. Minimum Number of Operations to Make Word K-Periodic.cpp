// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/


class Solution {
public:
	int minimumOperationsToMakeKPeriodic(string word, int k) {

		auto checker = map<string, int>();
		auto iter = map<string, int>::iterator();
		string temp;

		int max = 0;
		string best;


		for (int i = 0;i <= word.size()-k;i+=k)
		{
			temp.clear();

			for (int left = i;left < i+k;++left)
			{
				temp += word.at(left);
			}

			iter = checker.find(temp);
			if (iter == checker.end())
			{
				checker[temp] = 1;
			}
			else
			{
				checker[temp] = iter->second +1;
			}

			if (checker.find(temp)->second > max)
			{
				max = checker.find(temp)->second;
				best = temp;
			}
		}

		int result = 0;
		for (auto& singleMap : checker)
		{
			if (singleMap.first == best)
				continue;

			result += singleMap.second;
		}
		
		return result;
	}
};