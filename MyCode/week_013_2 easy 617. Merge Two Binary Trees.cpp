// https://leetcode.com/problems/merge-two-binary-trees/submissions/1253153077/

class Solution {
public:
	void dfs(const TreeNode* _leftNode, const TreeNode* _rightNode, TreeNode* _resultNode)
	{
		if (_leftNode == nullptr && _rightNode == nullptr)
			return;

		// 루트세팅
		if (_leftNode != nullptr && _rightNode != nullptr) //왼쪽 노드가 있다면,
		{
			_resultNode->val = _leftNode->val + _rightNode->val;

			if (_leftNode->left != nullptr || _rightNode->left != nullptr) //둘중 하나가 왼쪽 다리가 있다면
			{
				_resultNode->left = new TreeNode();
				dfs(_leftNode->left, _rightNode->left, _resultNode->left);
			}
			
			if (_leftNode->right != nullptr || _rightNode->right != nullptr)
			{
				_resultNode->right = new TreeNode();
				dfs(_leftNode->right, _rightNode->right, _resultNode->right);
			}

		}
		else if (_leftNode != nullptr) //왼쪽 노드만 있다면,
		{
			_resultNode->val = _leftNode->val;

			if (_leftNode->left != nullptr)
			{
				_resultNode->left = new TreeNode();
				dfs(_leftNode->left, nullptr, _resultNode->left);
			}

			if (_leftNode->right != nullptr)
			{
				_resultNode->right = new TreeNode();
				dfs(_leftNode->right, nullptr, _resultNode->right);
			}
		}
		else if (_rightNode != nullptr)
		{
			_resultNode->val = _rightNode->val;

			if (_rightNode->left != nullptr)
			{
				_resultNode->left = new TreeNode();
				dfs(_rightNode->left, nullptr, _resultNode->left);
			}

			if (_rightNode->right != nullptr)
			{
				_resultNode->right = new TreeNode();
				dfs(_rightNode->right, nullptr, _resultNode->right);
			}
			
		}

	}

	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode* resultNode=nullptr;
		if (root1 != nullptr || root2 != nullptr)
			resultNode = new TreeNode();

		dfs(root1, root2, resultNode);

		return resultNode;
	}
};