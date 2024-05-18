// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/1252523125/

class Solution {
public:
	int max = 0;

	void dfs(const Node* _node, const int& _depth)
	{
		if (_node == nullptr)
			return;
		
		if (_depth + 1 > max)
			max = _depth + 1;

		for (const auto& single : _node->children)
		{
			dfs(single, _depth + 1);
		}
	}

	int maxDepth(Node* root) {
		dfs(root, 0);

		return max;
	}
};