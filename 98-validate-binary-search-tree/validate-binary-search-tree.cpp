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
    vector<TreeNode*> res;
    void fun(TreeNode* root) {
        if(root==NULL) return;

        fun(root->left);
        res.push_back(root);
        fun(root->right);
        return;
    }
public:
    bool isValidBST(TreeNode* root) {
        bool nullFound = false;
        fun(root);
        for(int i=0; i<res.size()-1; i++) {
            if(res[i]==NULL && !nullFound) nullFound = true;

            else {
                if(res[i]==NULL) return false;
                if(res[i]->val >= res[i+1]->val) return false;
            }
        }
        return true;
    }
};