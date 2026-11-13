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
    TreeNode* fun(TreeNode* root, int v) {
        if(root==NULL) return NULL;

        if(root->val==v) return root;

        TreeNode* ans;
        if(root->val<v) {
            ans = fun(root->right, v);
        } else {
            ans = fun(root->left, v);
        }
        return ans;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return fun(root, val);
    }
};