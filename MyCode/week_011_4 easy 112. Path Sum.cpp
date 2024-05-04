// https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	bool __isSuccess = false;
	int __target = 0;
	void check(const TreeNode* _root, const int _before)
	{
		if (_root == nullptr || true == __isSuccess)
			return;

		int _current = _root->val + _before;

		if (_current == __target && _root->left == nullptr && _root->right == nullptr)
		{
			__isSuccess = true;
			return;
		}

		check(_root->left, _current);
		check(_root->right, _current);
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;

		__target = targetSum;

		check(root, 0);


		return __isSuccess;
	}
};
