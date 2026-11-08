/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void func(TreeNode* node, vector<int>& diary) {
        if(node==NULL) return;

        func(node->left, diary);
        diary.push_back(node->val);
        func(node->right, diary);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        func(root, res);
        return res;
    }
};