/*
https://school.programmers.co.kr/learn/courses/30/lessons/161990
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	const int xMax = wallpaper.size();
	const int yMax = wallpaper.at(0).size();

	//시작점
	int startX = xMax;
	int startY = yMax;

	//끝점
	int endX = 0;
	int endY = 0;

	for (int x = 0; x < xMax; x++) 
	{
		for (int y = 0; y < yMax; y++){
			if (wallpaper.at(x).at(y) == '#')
			{
				if (x < startX)
					startX = x;
				if (y < startY)
					startY = y;


				if (x > endX)
					endX = x;
				if (y > endY)
					endY = y;
			}
		}
	}


	return vector<int>{startX, startY, endX+1, endY+1};
}

void main()
{
	vector<string> list = vector<string>{ 
		".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...." };

	auto out = solution(list);

	for (auto single : out)
		cout << single << ", ";

	return;
}