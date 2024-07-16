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
    vector<vector<int>> v;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            vector<int> ans;
            int l=q.size();
            for(int i=0;i<l;i++){
                TreeNode* temp=q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            v.push_back(ans);
        }
        for(int i=0;i<v.size();i++){
            if(i%2==1) reverse(v[i].begin(),v[i].end());
        }
        return v;
    }
};