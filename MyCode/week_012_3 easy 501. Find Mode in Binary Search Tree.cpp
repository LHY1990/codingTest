// https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/1252493159/


class Solution {
public:
	int maxCount = 0;
	int temp = 0;
	map<int, int>::iterator iter;

	void dfs(const TreeNode* _node, map<int, int>& _finder)
	{
		if (_node == nullptr)
			return;

		iter = _finder.find(_node->val);
		if (iter == _finder.end())
		{
			_finder[_node->val] = 1;
			if (maxCount==0)
				maxCount = 1;
		}
		else
		{
			if (iter->second + 1 > maxCount)
				maxCount = iter->second + 1;

			_finder[_node->val] = iter->second + 1;
		}

		dfs(_node->left, _finder);
		dfs(_node->right, _finder);
	}

	vector<int> findMode(TreeNode* root) {
		auto finder = map<int, int>();

		dfs(root, finder);

		auto out = vector<int>(0);
		for (const auto& single : finder)
		{
			if (single.second == maxCount)
				out.push_back(single.first);
		}

		return out;

	}
};