// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
public:
    void inOrder(TreeNode* _input, vector<int>& _list)
    {
        if (_input == nullptr)
            return;

        inOrder(_input->left, _list);
        _list.push_back(_input->val);
        inOrder(_input->right, _list);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out = vector<int>(0);

        inOrder(root, out);

        return out;
    }
};

