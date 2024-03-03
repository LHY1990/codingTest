/*
https://school.programmers.co.kr/learn/courses/30/lessons/120866
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution(vector<vector<int>> board) {

	const int length = board.size();

	//1차 처리 좌우
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < length; x++) {

			if (board.at(y).at(x) == 1)
			{
				//왼쪽칸 체크
				if (0 <= x - 1)
					if (board.at(y).at(x - 1) < 1)
						board.at(y).at(x - 1) = 2;

				//오른칸 체크
				if (x + 1 < length)
					if (board.at(y).at(x + 1) < 1)
						board.at(y).at(x + 1) = 2;

				//위칸 체크
				if (y - 1 >= 0)
					if (board.at(y - 1).at(x) < 1)
						board.at(y - 1).at(x) = 2;

				//아래칸 체크
				if (y + 1 < length)
					if (board.at(y + 1).at(x) < 1)
						board.at(y + 1).at(x) = 2;

				//왼쪽위 체크
				if (x - 1 >= 0 && y - 1 >= 0)
					if (board.at(y - 1).at(x - 1) < 1)
						board.at(y - 1).at(x - 1) = 2;

				//오른위체크
				if (x + 1 < length && y - 1 >= 0)
					if (board.at(y - 1).at(x + 1) < 1)
						board.at(y - 1).at(x + 1) = 2;

				//왼아래 체크
				if (x - 1 >= 0 && y + 1 < length)
					if (board.at(y + 1).at(x - 1) < 1)
						board.at(y + 1).at(x - 1) = 2;

				//오른 아래 체크
				if (x + 1 < length && y + 1 < length)
					if (board.at(y + 1).at(x + 1) < 1)
						board.at(y + 1).at(x + 1) = 2;
			}
		}
	}

	int count = 0;
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < length; x++)
		{
			if (board.at(y).at(x) == 0)
				++count;

			cout << board.at(y).at(x) << " ";
		}
		cout << endl;
	}

	return count;
}

void main()
{

	vector<vector<int>> board = vector<vector<int>>(0);

	board.push_back(vector<int>{0, 0, 0, 0, 1});
	board.push_back(vector<int>{0, 1, 0, 1, 0});
	board.push_back(vector<int>{0, 1, 0, 0, 0});
	board.push_back(vector<int>{0, 0, 1, 0, 0});
	board.push_back(vector<int>{0, 1, 0, 0, 0});

	//board.push_back(vector<int>{1, 1, 1});
	//board.push_back(vector<int>{0, 0, 0});
	//board.push_back(vector<int>{0, 0, 0});

	cout << solution(board) << endl;
}