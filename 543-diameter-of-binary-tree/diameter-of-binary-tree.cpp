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
    int res = 0;
    int fun(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int a = fun(root->left);
        int b = fun(root->right);
        int sum = a+b;
        res = max(res, sum);
        return (max(a, b))+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return res;
    }
};