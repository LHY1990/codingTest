// https://leetcode.com/problems/flood-fill/description/


class Solution {
public:
	int sizeY = 0;
	int sizeX = 0;

	void dfs(const vector<vector<int>>& _image, bool* _isVisited, const int& _originalColor, vector<pair<int, int>>& _pairList, const int& _x, const int& _y)
	{
		if (true == _image.empty())
			return;

		if (_y < 0 || _y >= sizeY)
			return;

		if (_x < 0 || _x >= sizeX)
			return;

		if (true == _isVisited[_y * sizeX + _x])
			return;

		// 방문처리
		_isVisited[_y * sizeX + _x] = true; 

		// 같은 색이면 등록
		if (_image.at(_y).at(_x) == _originalColor) 
		{
			_pairList.push_back(pair<int, int>(_x, _y));
		}
		else
		{
			return;
		}

		// 좌우와리가리 하면서 돌아다니기
		dfs(_image, _isVisited, _originalColor, _pairList, _x + 1, _y);
		dfs(_image, _isVisited, _originalColor, _pairList, _x - 1, _y);
		dfs(_image, _isVisited, _originalColor, _pairList, _x, _y + 1);
		dfs(_image, _isVisited, _originalColor, _pairList, _x, _y - 1);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		auto pairList = vector<pair<int, int>>(0);

		const int originalColor = image.at(sr).at(sc);
		const int maxSize = image.size() * image.at(0).size();

		sizeY = image.size();
		sizeX = image.at(0).size();

		bool* isVisited = new bool[maxSize] {false, };

		dfs(image, isVisited, originalColor, pairList, sc, sr);

		// result에 image 값 color로 변경해서 넣기
		for (const auto& singlePair : pairList)
		{
			image.at(singlePair.second).at(singlePair.first) = color;
		}

		delete[] isVisited;

		return image;
	}
};