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
    bool fun(TreeNode* l, TreeNode* r) {
        if(r==NULL && l==NULL) {
            return true;
        }
        if(r==NULL || l==NULL) {
            return false;
        }
        if(r->val != l->val) {
            return false;
        }

        bool b1 = fun(l->left, r->right);
        bool b2 = fun(l->right, r->left);

        if(b1==true && b2==true) return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return fun(root->left, root->right);
    }
};