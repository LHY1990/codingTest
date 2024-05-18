// https://leetcode.com/problems/island-perimeter/description/


class Solution {
public:
	int sideLength = 0;

	const int LAND = 1;
	const int WATER = 0;

	int maxSizeX = 0;
	int maxSizeY = 0;

	vector<pair<int, int>> landList = vector<pair<int, int>>(0);

	void findLand(const vector<vector<int >>& _map, const int& _x, const int& _y, bool* _visited)
	{
		if (_x < 0 || _x >= maxSizeX)
			return;

		if (_y < 0 || _y >= maxSizeY)
			return;

		if (true == _visited[maxSizeX * _y + _x])
			return;

		_visited[maxSizeX * _y + _x] = true;

		if (_map.at(_y).at(_x) == LAND)
			landList.push_back(make_pair(_x, _y));

		findLand(_map, _x + 1, _y, _visited);
		findLand(_map, _x - 1, _y, _visited);
		findLand(_map, _x, _y + 1, _visited);
		findLand(_map, _x, _y - 1, _visited);
	}

	void checkLine(const int& _x, const int& _y, vector<vector<int>>& _map)
	{

		//왼쪽이 넘어가거나 water면 1추가
		if (_x - 1 < 0 || _map.at(_y).at(_x - 1) == WATER)
			++sideLength;
		if (_x + 1 >= maxSizeX || _map.at(_y).at(_x + 1) == WATER)
			++sideLength;
		if (_y - 1 < 0 || _map.at(_y - 1).at(_x) == WATER)
			++sideLength;
		if (_y + 1 >= maxSizeY || _map.at(_y + 1).at(_x) == WATER)
			++sideLength;
	}

	int islandPerimeter(vector<vector<int>>& grid) {

		maxSizeX = grid.at(0).size();
		maxSizeY = grid.size();

		auto visited = new bool[maxSizeX * maxSizeY]{ false, };

		findLand(grid, 0, 0, visited);


		for (const auto& singlePair : landList)
		{
			checkLine(singlePair.first, singlePair.second, grid);
		}

		delete[] visited;

		return sideLength;
	}
};