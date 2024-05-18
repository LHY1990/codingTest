// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/


class Solution {
public:
	map<int, vector<int64_t>>::iterator iter;

	void dfs(const TreeNode* _node, map<int, vector<int64_t>>& _listMap, const int& _depth)
	{
		if (_node == nullptr)
			return;

		// 뎁스 초기화
		if (_listMap.find(_depth) == _listMap.end())
			_listMap[_depth] = vector<int64_t>(0);

		iter = _listMap.find(_depth); // 무조건 있다
		iter->second.push_back(_node->val);

		dfs(_node->left, _listMap, _depth + 1);
		dfs(_node->right, _listMap, _depth + 1);
	}

	vector<double> averageOfLevels(TreeNode* root) {
		int depth = 0;
		auto outMap = map<int, vector<int64_t>>();

		dfs(root, outMap, depth);

		//맵을 바탕으로 각 뎁스별 갯수랑 합으로 값을 구한뒤 리스트 반환
		auto resultList = vector<double>(0);

		int64_t sum = 0;
		double count = 0;
		//int mapDepth = 0;
		for (const auto& singleIter : outMap)
		{
			sum = 0;
			count = 0;
			//mapDepth = singleIter.first; 뎁스는 쓸일이 없네

			for (const auto& singleInt : singleIter.second) // vector<int>
			{
				sum += singleInt;
				++count;
			}

			if (count > 0)
				resultList.push_back(sum / count);
		}


		return resultList;
	}
};

