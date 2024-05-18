// https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

class Solution {
public:
	void dfs(const Node* _node, vector<int>& _list)
	{
		if (_node == nullptr)
			return;

		_list.push_back(_node->val);

		for (const auto& single : _node->children)
			dfs(single, _list);
	}

	vector<int> preorder(Node* root) {
		auto out = vector<int>(0);

		dfs(root, out);

		return out;
	}
};