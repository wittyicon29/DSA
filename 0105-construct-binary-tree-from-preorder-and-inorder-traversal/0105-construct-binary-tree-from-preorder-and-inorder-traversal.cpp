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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0, i = 0;
        return build(preorder, inorder, p, i, INT_MAX);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& p, int& i, int stop) {
        if(i < inorder.size() && inorder[i] != stop) {
            TreeNode* root = new TreeNode(preorder[p++]);
            root->left = build(preorder, inorder, p, i, root->val);
            i++;
            root->right = build(preorder, inorder, p, i , stop);
            return root;
        }
        return nullptr;
    }
};