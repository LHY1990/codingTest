// https://leetcode.com/problems/invert-binary-tree/description/

class Solution {
public:


	void invert(TreeNode* _node)
	{
		if (_node == nullptr)
			return;

		auto temp = _node->left;
		_node->left = _node->right;
		_node->right = temp;

		invert(_node->left);
		invert(_node->right);
	}

	TreeNode* invertTree(TreeNode* root) {

		invert(root);

		return root;
	}
};
