// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/1253161338/


class Solution {
public:
	void dfs(const TreeNode* _node, vector<int>& _list)
	{
		if (_node == nullptr)
			return;

		_list.push_back(_node->val);

		dfs(_node->left, _list);
		dfs(_node->right, _list);
	}

	bool findTarget(TreeNode* root, int k) {
		auto list = vector<int>(0);
		dfs(root, list);

		sort(list.begin(), list.end());

		for (int left = 0;left < list.size()-1;++left)
		{
			for (int right = left + 1;right < list.size();++right)
			{
				if (list.at(right) + list.at(left) == k)
					return true;
			}
		}

		return false;
	}
};