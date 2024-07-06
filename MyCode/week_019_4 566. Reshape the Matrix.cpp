// https://leetcode.com/problems/reshape-the-matrix/description/

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		const int matRow = mat.size();
		const int matCol = mat.at(0).size();

		if (r * c != matRow * matCol)
			return mat;


		vector<int> list = vector<int>(0);

		for (int i = 0;i < matRow;++i)
		{
			for (int j = 0;j < matCol;++j)
			{
				list.push_back(mat.at(i).at(j));
			}
		}

		auto result = vector<vector<int>>(0);

		for (int i = 0;i < list.size();++i)
		{
			if (i % c == 0)
			{
				result.push_back(vector<int>(0));
			}

			result.back().push_back(list.at(i));
		}

		return result;
	}
};