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
    bool ans = false;
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL and subRoot!=NULL) return false;
        if(root!=NULL and subRoot == NULL) return false;
        if(root == NULL and subRoot == NULL) return true;
        return root->val == subRoot->val and check(root->left,subRoot->left) and check(root->right,subRoot->right);
    }
    void inorder(TreeNode* root,TreeNode* subRoot)
    {
        if(root == NULL) return;
        inorder(root->left,subRoot);
        if(root->val ==subRoot->val)
        {
            ans = ans or check(root,subRoot);
            cout << root->val << " " << ans;
        }
        inorder(root->right,subRoot);
        return ;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        inorder(root,subRoot);
        return ans;
    }
};