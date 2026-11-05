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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();
            vector<int> temp;

            while (levelSize--) {

                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left != NULL)
                    q.push(t->left);

                if (t->right != NULL)
                    q.push(t->right);
            }

            res.push_back(temp);
        }

        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        levelOrder(root);
        
        vector<int>final;

        for (int i = 0; i < res.size(); i++) {
            final.push_back(res[i].back());
        }

        return final;

    }
};
