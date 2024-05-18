// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/


class Solution {
public:
	void dfs(TreeNode* _node, vector<int>& _list)
	{
		if (_node == nullptr)
			return;

		_list.push_back(_node->val);

		dfs(_node->left, _list);
		dfs(_node->right, _list);
	}

	int minDiffInBST(TreeNode* root) {
		if (root == nullptr)
			return 0;

		auto resultList = vector<int>(0);

		dfs(root, resultList);

		sort(resultList.begin(), resultList.end());

		int min = 1000000;
		int temp = 0;
		for (int i = 0; i < resultList.size()-1; ++i)
		{
			temp = abs(resultList.at(i) - resultList.at(i + 1));
			if (temp < min)
				min = temp;

			if (temp == 0)
				return 0;
		}

		return min;
	}
};
