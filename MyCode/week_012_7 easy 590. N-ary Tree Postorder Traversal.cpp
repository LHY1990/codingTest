// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

class Solution {
public:
	void dfs(const Node* _node, vector<int>& _list)
	{
		if (_node == nullptr)
			return;

		for (const auto& single : _node->children)
			dfs(single, _list);

		_list.push_back(_node->val);
	}

	vector<int> postorder(Node* root) {
		auto out = vector<int>(0);

		dfs(root, out);

		return out;
	}
};