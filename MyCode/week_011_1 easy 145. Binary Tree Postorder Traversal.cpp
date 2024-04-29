// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

class Solution {
public:
	void postOrder(const TreeNode* _root, vector<int>& _out)
	{
		if (_root == nullptr)
			return;


		postOrder(_root->left, _out);
		postOrder(_root->right, _out);
		_out.push_back(_root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		auto out = vector<int>(0);

		postOrder(root, out);

		return out;
	}
};