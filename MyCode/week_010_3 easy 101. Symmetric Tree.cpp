// https://leetcode.com/problems/symmetric-tree/description/


class Solution {
public:
	void dfsLeft(TreeNode* _root, vector<int>& _vector)
	{
		if (_root == nullptr)
		{
			_vector.push_back(-101);
			return;
		}

		dfsLeft(_root->left, _vector);
		dfsLeft(_root->right, _vector);
		_vector.push_back(_root->val);
	}

	void dfsRight(TreeNode* _root, vector<int>& _vector)
	{
		if (_root == nullptr)
		{
			_vector.push_back(-101);
			return;
		}

		dfsRight(_root->right, _vector);
		dfsRight(_root->left, _vector);
		_vector.push_back(_root->val);
	}

	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;

		vector<int> left = vector<int>(0);
		vector<int> right = vector<int>(0);

		dfsLeft(root->left, left);
		dfsRight(root->right, right);

		if (left.size() != right.size())
			return false;

		for (int i = 0;i < left.size();++i)
		{
			if (left.at(i) != right.at(i))
				return false;
		}

		return true;

	}
};