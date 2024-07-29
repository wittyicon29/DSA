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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        int i = 1;
        long long int x = LLONG_MAX;

        while(st.size() > 0 || node) {
            if(node) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode* temp = st.top();
                st.pop();
                if(i == k) return temp->val;
                if(x != LLONG_MAX) {
                    x = temp->val;
                }
                i++;
                node = temp->right;
            }
        }
        return -1;
    }
};