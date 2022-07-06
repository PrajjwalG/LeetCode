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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int targetSum, vector<int>& curr)
    {
        if(root == NULL) return ;
        if(root->val == targetSum and root->left == NULL and root->right == NULL) 
        {
            curr.push_back(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return ;
        }
        curr.push_back(root->val);
        dfs(root->left,targetSum - root->val,curr);
        dfs(root->right, targetSum - root->val, curr);
        curr.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        dfs(root,targetSum,curr);
        return ans;
    }
};