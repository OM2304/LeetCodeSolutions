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
    vector<vector<int>> res;
    void fun(TreeNode* root, int sum, int t, vector<int> v) {
        if(root==NULL) return;

        sum+=root->val;
        v.push_back(root->val);

        if(root->left==NULL && root->right==NULL) {
            if(sum==t) {
                res.push_back(v);
                return;
            }
        }

        fun(root->left, sum, t, v);
        fun(root->right, sum, t, v);
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        fun(root, 0, targetSum, v);
        return res;
    }
};