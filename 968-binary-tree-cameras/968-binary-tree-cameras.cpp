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
    int cameras = 0;
    int dfs(TreeNode* root)
    {
        // return -1 if u need a camera
        // return 0 if u  have a camera
        // return 1 if u are convered
        if(root == NULL) return 1;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l == -1 or r == -1)
        {
            cameras++;
            return 0;
        }
        if(l == 0 or  r == 0) return 1;
        
        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
        
        if(dfs(root) == -1) cameras++;
        return cameras;
    }
};