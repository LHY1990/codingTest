// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

class Solution {
public:
	void dfs(TreeNode* _node, set<int>& _set)
	{
		if (_node == nullptr)
			return;

		_set.insert(_node->val);

		dfs(_node->left, _set);
		dfs(_node->right, _set);
	}

	int findSecondMinimumValue(TreeNode* root) {
		if (root == nullptr)
			return -1;

		auto resultSet = set<int>();

		dfs(root, resultSet);

		if (resultSet.size() < 2)
			return -1;

		auto list = vector<int>(resultSet.begin(), resultSet.end());

		copy(resultSet.begin(), resultSet.end(), list.begin());
		sort(list.begin(), list.end());

		return list.at(1);
	}
};