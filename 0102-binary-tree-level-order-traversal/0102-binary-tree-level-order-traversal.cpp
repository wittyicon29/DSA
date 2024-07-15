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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        if(!root) return result;

        while(!q.empty()) {
            vector<int> v;
            int s = q.size();

            for(int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            result.push_back(v);
        }
        return result;
    }
};