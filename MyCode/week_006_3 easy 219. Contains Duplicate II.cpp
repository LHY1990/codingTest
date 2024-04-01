// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		if (nums.size() == 1)
			return false;

		unordered_map<int, vector<int>> map = unordered_map<int, vector<int>>();
		unordered_map<int, vector<int>>::iterator iter;

		for (int i = 0;i < nums.size();i++)
		{
			iter = map.find(nums.at(i));
			
			// if not exist
			if (iter == map.end())
			{
				map[nums.at(i)] = vector<int>(0);
				map.find(nums.at(i))->second.push_back(i);
			}
			else {
				// compare last index only
				if (abs(i - iter->second.back()) <= k)
					return true;
				iter->second.push_back(i);
			}
		}
		return false;
	}
};