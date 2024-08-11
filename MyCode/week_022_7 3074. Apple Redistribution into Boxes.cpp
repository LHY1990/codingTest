// https://leetcode.com/problems/apple-redistribution-into-boxes/submissions/1309093120/

class Solution {
public:
	int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
		int sum = 0;
		for (const int& single : apple)
		{
			sum += single;
		}

		sort(capacity.begin(), capacity.end(), greater<int>()); //내림차순
		int size = 0;
		int count = 0;
		for (const int& single : capacity)
		{
			++count;
			size += single;
			if (size >= sum)
			{
				return count;
			}
		}

		return capacity.size();
	}
};