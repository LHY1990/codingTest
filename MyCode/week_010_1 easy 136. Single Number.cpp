// https://leetcode.com/problems/single-number/description/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> out = map<int, int>();
		map<int, int>::iterator iter;
		
		for (int i = 0;i < nums.size();++i)
		{
			iter = out.find(nums.at(i));
			if (iter == out.end())
				out[nums.at(i)] = 1;
			else
				++iter->second;
		}

		for (iter = out.begin();iter != out.end();++iter)
			if (iter->second == 1)
				return iter->first;

		return -1;
	}
};