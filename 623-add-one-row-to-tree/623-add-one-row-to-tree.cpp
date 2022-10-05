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
    void solve(TreeNode * root, int val, int depth, int level)
    {
        if(!root)return;
        
        if(level == depth-1)
        {
            TreeNode * tl = new TreeNode(val);
            TreeNode * tr = new TreeNode(val);
            tl->left = root->left;
            tr->right= root->right;
            root->left = tl;
            root->right = tr;
        }
        
        solve(root->left, val, depth, level+1);
        solve(root->right, val, depth, level+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode * newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root, val, depth, 1);
        return root;
    }
};