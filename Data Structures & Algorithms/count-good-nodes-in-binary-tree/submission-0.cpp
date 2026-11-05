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
    int count = 0;
    void fun(TreeNode* root,int maxi){
        if(!root) return;

        if (root->val >= maxi) {
            count++;
        }

        maxi = max(maxi, root->val);

        fun(root->left, maxi);
        fun(root->right, maxi);
        
    }
    int goodNodes(TreeNode* root) {
        count = 0;
        fun(root,INT_MIN);
        return count;
    }
};
