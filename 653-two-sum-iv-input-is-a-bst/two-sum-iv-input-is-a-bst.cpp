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
    stack<TreeNode*> asc;
    stack<TreeNode*> des;
    
public:
    TreeNode* getSmall() {
        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightChild = small->right;
        while(rightChild) {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }
    TreeNode* getBig() {
        TreeNode* big = des.top();
        des.pop();

        TreeNode* leftChild = big->left;
        while(leftChild) {
            des.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        TreeNode* t = root;
        while(t) {
            asc.push(t);
            t=t->left;
        }

        t=root;
        while(t) {
            des.push(t);
            t=t->right;
        }

        TreeNode* i = getSmall();
        TreeNode* j = getBig();
        while(i&&j && i!=j && i->val < j->val) {
            int sum = i->val+j->val;

            if(sum==k) return true;

            if(sum>k) {
                j = getBig();
            } else {
                i = getSmall();
            }
        }
        return false;
    }
};