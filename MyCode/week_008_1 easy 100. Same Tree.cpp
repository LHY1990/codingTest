// https://leetcode.com/problems/same-tree/description/

class Solution {
public:
    void preOrder(TreeNode* _root, vector<int>& _outList)
    {
        if (_root == nullptr)
            return;

        _outList.push_back(_root->val);

        if (_root->right == nullptr)
            _outList.push_back(-1);
        if (_root->left == nullptr)
            _outList.push_back(-2);

        preOrder(_root->right, _outList);
        preOrder(_root->left, _outList);
    }

    void rPreOrder(TreeNode* _root, vector<int>& _outList)
    {
        if (_root == nullptr)
            return;

        _outList.push_back(_root->val);

        if (_root->left == nullptr)
            _outList.push_back(-1);
        if (_root->right == nullptr)
            _outList.push_back(-2);

        preOrder(_root->left, _outList);
        preOrder(_root->right, _outList);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pList = vector<int>(0);
        vector<int> qList = vector<int>(0);

        preOrder(p, pList);
        preOrder(q, qList);

        if (pList.size() != qList.size())
            return false;

        for (int i = 0;i < pList.size();++i)
        {
            if (pList.at(i) != qList.at(i))
                return false;
        }


        return true;
    }
};