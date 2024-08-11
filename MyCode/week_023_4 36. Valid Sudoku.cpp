// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		auto checker = set<char>();
		auto count = 0;


		for (int h = 0;h < board.size();++h)
		{
			// 가로 체커 초기화
			checker.clear();
			count = 0;

			for (int w = 0;w < board.at(h).size();++w)
			{
				if (board.at(h).at(w) != '.')
				{
					checker.insert(board.at(h).at(w));
					++count;
				}
			}

			// 가로에 중복이 있다면,
			if (count != checker.size())
				return false;
		}
		// 가로체크 완

		for (int w = 0;w < 9;++w)
		{
			count = 0;
			checker.clear();

			for (int h = 0;h < 9;++h)
			{
				if (board.at(h).at(w) != '.')
				{
					++count;
					checker.insert(board.at(h).at(w));
				}

				if (count != checker.size())
					return false;
			}
		}
		// 세로체크 완
		for (int i = 0;i < 9;i+=3)
		{
			for (int j = 0;j < 9;j+=3)
			{
				checker.clear();
				count = 0;
				
				//안에서 9개 반복
				for (int w = j;w < j + 3;++w)
				{
					for (int h = i; h < i + 3;++h)
					{
						if (board.at(h).at(w) != '.')
						{
							++count;
							checker.insert(board.at(h).at(w));
						}
					}
				}

				if (checker.size() != count)
					return false;
			}
		}
		return true;
	}
};