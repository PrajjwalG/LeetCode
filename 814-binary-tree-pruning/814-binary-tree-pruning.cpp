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
    bool solve(TreeNode* root)
    {
        if(root == NULL) return false;
        bool lh = solve(root->left);
        bool rh = solve(root->right);
        
        if(!lh) root->left = NULL;
        if(!rh) root->right = NULL;
        return root->val or lh or rh;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool t = solve(root);
        if(!t) return NULL;
        return root;
    }
};