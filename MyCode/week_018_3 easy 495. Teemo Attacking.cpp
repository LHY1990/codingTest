// https://leetcode.com/problems/teemo-attacking/description/

class Solution {
public:

	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.size() == 0)
			return 0;
		if (timeSeries.size() == 1)
			return duration;

		int result = 0;
		int diff;
		for (int i = 0;i < timeSeries.size() - 1;++i)
		{
			diff = timeSeries.at(i + 1) - timeSeries.at(i);
			if (diff < duration)
				result += diff;
			else
				result += duration;

		}
        result += duration;

		return result;
	}
};