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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildTreeHelper(preorder, index, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }
private:
    TreeNode* buildTreeHelper(std::vector<int>& preorder, int& index, int minVal, int maxVal) {
        // Base case: if we've processed all elements or the current value is out of bounds
        if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal) {
            return nullptr;
        }

        // The current value is valid; create the node
        TreeNode* root = new TreeNode(preorder[index++]);

        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, index, minVal, root->val);
        root->right = buildTreeHelper(preorder, index, root->val, maxVal);

        return root;
    }
};