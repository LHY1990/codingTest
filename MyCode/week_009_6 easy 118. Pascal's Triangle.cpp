// https://leetcode.com/problems/pascals-triangle/submissions/1234649635/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> out = vector<vector<int>>(0);
		
		vector<int> before;
		int temp = 0;

		for (int i = 0;i < numRows;++i)
		{
			if (i == 0)
			{
				out.push_back(vector<int>({ 1 }));
				continue;
			}

			before = out.at(i - 1);

			auto current = vector<int>(0);
			current.push_back(before.at(0));

			for (int left = 0;left < before.size();++left)
			{
				temp = 0;
				temp += before.at(left);

				if (left + 1 < before.size()) // right
					temp += before.at(left + 1);

				current.push_back(temp);
			}

			out.push_back(current);
		}


		return out;
	}
};