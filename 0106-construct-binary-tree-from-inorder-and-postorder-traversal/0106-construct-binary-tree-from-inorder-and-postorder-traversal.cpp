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
    TreeNode* makeTree(vector<int> &postorder, vector<int> &inorder, int stop){
        if(inorder.empty() || inorder.back() == stop)
            return NULL;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        root->right = makeTree(postorder, inorder, root->val);
        inorder.pop_back();
        root->left = makeTree(postorder, inorder, stop);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return makeTree(postorder, inorder, INT_MIN);
    }
};