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
    int ans = 0;
    int c = 0;
    void inorder(TreeNode* root, int k)
    {
        if(root == NULL || c>k) return ;
        inorder(root->left,k);
        ++c;
        if(c == k) 
        {
            ans = root->val;
            return;
        }
        if(c<k)
        inorder(root->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> tree;
        int c = 0;
        inorder(root,k);
        return ans;
    }
};