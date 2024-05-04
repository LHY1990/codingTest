// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

class Solution {
public:
	int __minDepth = 1000000;

	void check(TreeNode* _root, int _depth)
	{
		if (_root == nullptr)
			return;

		if (_root->left == nullptr && _root->right == nullptr)
		{
			if (__minDepth > _depth + 1)
				__minDepth = _depth + 1;
		}

		check(_root->left, _depth + 1);
		check(_root->right, _depth + 1);
	}

	int minDepth(TreeNode* root) {

		if (root == nullptr)
			return 0;

		int depth = 0;
		check(root, depth);


		return __minDepth;
	}
};