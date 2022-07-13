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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> node;
        
        if(root == NULL) return node;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n;i++)
            {
                if(q.front()!=NULL)
                {
                    temp.push_back(q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(temp.size()!=0)
                node.push_back(temp);
        }
        return node;
    }
};