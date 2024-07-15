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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minimum = INT_MAX, maximum = INT_MIN;
        map<pair<int, int>, vector<int>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            TreeNode* temp = q.front().first;
            int v = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            minimum = min(minimum, v);
            maximum = max(maximum, v);

            mp[{v, level}].push_back(temp->val);

            if(temp->left) q.push({temp->left, {v - 1, level + 1}});
            if(temp->right) q.push({temp->right, {v + 1, level + 1}});
        }

        vector<vector<int>> result(maximum - minimum + 1);

        for(auto i : mp) {
            sort(i.second.begin(), i.second.end());
            
            for(auto i2: i.second) {
                result[i.first.first - minimum].push_back(i2);
            }
        }
        return result;
    }
};