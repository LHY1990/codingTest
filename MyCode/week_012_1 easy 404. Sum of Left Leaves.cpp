// https://leetcode.com/problems/sum-of-left-leaves/description/


class Solution {
public:
	int result = 0;

	void loop(TreeNode* _node)
	{
		if (_node == nullptr)
			return;

		if (_node->left != nullptr && _node->left->left == nullptr && _node->left->right == nullptr)
			result += _node->left->val;

		loop(_node->left);
		loop(_node->right);
	}

	int sumOfLeftLeaves(TreeNode* root) {

		loop(root);

		return result;
	}
};