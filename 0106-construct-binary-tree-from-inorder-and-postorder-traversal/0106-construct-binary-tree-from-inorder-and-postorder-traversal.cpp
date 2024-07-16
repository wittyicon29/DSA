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
TreeNode* build(int &Postindex,int inI,int inJ,vector<int>&inorder, vector<int>&postorder)
{
    if(Postindex<0 || inI>inJ) // if the postorder index i.e(Postindex) is negative or the inI and inJ have collided 
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(postorder[Postindex--]);
// making the root taking value of the Postindex index from the postorder vector (starting from the ending) as postorder(left right root) 
    int i;
// checking for the root value in the inorder array ,and storing its index in i
    for( i=inI;i<=inJ;i++)
    {
        if(inorder[i]==root->val)
        {
            break;
        }
    }
// inorder(left root right)
// the right side of i is the root'right
    root->right=build(Postindex,i+1,inJ,inorder,postorder); 
// the left side of i is the root's left
     root->left=build(Postindex,inI,i-1,inorder,postorder);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;// caculating the last index of the postorder vector
        return build(index,0,inorder.size()-1,inorder,postorder);
    }
};