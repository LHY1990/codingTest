// https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		sort(nums.begin(), nums.end()); // 오름차순

		auto checker = map<int, int>();
		auto iter = map<int, int>::iterator();

		int dup = 0;
		int notIn = 0;

		for (auto single : nums)
		{
			iter = checker.find(single);
			if (iter != checker.end()) //중복이 아니면
			{
				dup = single;
			}
			else
			{
				checker[single] = 1;
			}
		}

		for (int i = 1;i <= nums.size();++i)
		{
			iter = checker.find(i);
			if (iter == checker.end())
			{
				notIn = i;
				break;
			}
		}


		// 반복되는거 없는것
		return vector<int>({ dup, notIn });
	}

};