// https://leetcode.com/problems/count-complete-tree-nodes/submissions/1248866715/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
	void check(const TreeNode* _root, int& _count)
	{
		if (_root == nullptr)
			return;

		++_count;

		check(_root->left, _count);
		check(_root->right, _count);
	}

	int countNodes(TreeNode* root) {
		int result = 0;

		check(root, result);

		return result;
	}
};
