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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        int ltoR = 1;
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int lvlSize = q.size();
            vector<int> tmp(lvlSize);
            int first = 0;
            int last = lvlSize-1;

            while(lvlSize--) {
                TreeNode* t = q.front();
                q.pop();

                if(ltoR) {
                    tmp[first] = t->val;
                    first++;
                } else {
                    tmp[last] = t->val;
                    last--;
                }

                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            }
            res.push_back(tmp);
            ltoR = 1-ltoR;
        }
        return res;
    }
};