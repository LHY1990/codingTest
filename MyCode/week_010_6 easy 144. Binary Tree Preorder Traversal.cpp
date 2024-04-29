// https://leetcode.com/problems/binary-tree-preorder-traversal/description/


class Solution {
public:
	void preOrder(const TreeNode* _root, vector<int>& _out)
	{
		if (_root == nullptr)
			return;


		_out.push_back(_root->val);
		preOrder(_root->left, _out);
		preOrder(_root->right, _out);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		auto out = vector<int>(0);

		preOrder(root, out);

		return out;
	}
};