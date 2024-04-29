// https://leetcode.com/problems/summary-ranges/description/

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		auto result = vector<string>(0);
		if (nums.size() == 0)
			return result;

		auto list = vector<pair<int, int>>(0);

		for (int current : nums)
		{
			//신규로 넣는 경우
			if (list.size() == 0 || list.back().second + 1 != current)
			{
				auto curPair = pair<int, int>(current, current);
				list.push_back(curPair);
			}
			else {
				list.back().second = current;
			}
		}

		for (auto single : list)
		{
			if (single.first == single.second)
			{
				result.push_back(to_string(single.first));
			}
			else
			{
				auto tempString = to_string(single.first) + "->" + to_string(single.second);
				result.push_back(tempString);
			}
		}

		return result;
	}
};