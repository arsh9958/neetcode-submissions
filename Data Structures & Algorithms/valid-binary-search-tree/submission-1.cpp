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
    vector<int>final;
    void inOrder(TreeNode* root){
        if(!root) return;

        inOrder(root->left);
        final.push_back(root->val);
        inOrder(root->right);
    }
    bool isSorted(vector<int>final){
        for(int i = 1;i<final.size();i++){
            if(final[i-1]>=final[i]) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        inOrder(root);
        bool res = isSorted(final);
        return res;
    }
};
