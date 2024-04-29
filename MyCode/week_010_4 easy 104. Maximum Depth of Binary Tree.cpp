// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
	int m_nMaxDepth = 0;
	void search(TreeNode* _head, const int& _depth)
	{
		if (_head == nullptr)
			return;

		if (m_nMaxDepth < _depth)
			m_nMaxDepth = _depth;

		search(_head->left, _depth+1);
		search(_head->right, _depth+1);
	}

	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		search(root, 1);


		return 	m_nMaxDepth;
	}
};