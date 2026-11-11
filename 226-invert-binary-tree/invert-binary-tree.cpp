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
    void fun(TreeNode* r) {
        if(r==NULL) return;

        swap(r->left, r->right);
        fun(r->left);
        fun(r->right);
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        fun(root);
        return root;
    }
};