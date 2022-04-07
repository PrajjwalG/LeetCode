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
    int maxheight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(maxheight(root->left),maxheight(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
       if(root==NULL)
        {
            return 0;
        }
        int l=diameterOfBinaryTree(root->left);
        int r=diameterOfBinaryTree(root->right);
        int ans=maxheight(root->left)+maxheight(root->right);
        return max(ans,max(l,r));
        
    }
};