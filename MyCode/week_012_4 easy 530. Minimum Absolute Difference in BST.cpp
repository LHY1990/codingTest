// https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/1252502101/

class Solution {
public:
	vector<int> list = vector<int>(0);

	void dfs(const TreeNode* _node)
	{
		if (_node == nullptr)
			return;

		list.push_back(_node->val);

		dfs(_node->left);
		dfs(_node->right);
	}

	int getMinimumDifference(TreeNode* root) {
		int min = 10000000;

		dfs(root);

		sort(list.begin(), list.end());
		int right = 0;
		int temp = 0;
		for (int left = 0;left < list.size() - 1;++left)
		{
			right = left + 1;
			temp = abs(list.at(left) - list.at(right));
			if (temp < min)
				min = temp;
		}


		return min;
	}
};