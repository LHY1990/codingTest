// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/


class Solution {
public:
	int countPrefixSuffixPairs(vector<string>& words) {
		string prefix;
		string target;

		bool isPrefix ,isSuffix = false;
		int count = 0;

		for (int left = 0;left < words.size() - 1;++left)
		{
			for (int right = left + 1;right < words.size();++right)
			{
				prefix = words.at(left);
				target = words.at(right);
				isPrefix = true;
                isSuffix = true;

				if (prefix.size() > target.size())
					continue;

				for (int i = 0;i < prefix.size();++i)
				{
					if (prefix.at(i) != target.at(i))
					{
						isPrefix = false;
						break;
					}
				}

				reverse(prefix.begin(), prefix.end());
				reverse(target.begin(), target.end());

				for (int i = 0;i < prefix.size();++i)
				{
					if (prefix.at(i) != target.at(i))
					{
						isSuffix = false;
						break;
					}
				}

				if (isPrefix && isSuffix)
					++count;


			}
		}

		return count;
	}
};