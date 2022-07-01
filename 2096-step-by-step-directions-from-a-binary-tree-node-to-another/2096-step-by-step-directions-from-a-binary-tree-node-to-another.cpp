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
    bool dfs(TreeNode* root, int value, string& s)
    {
        if(root == NULL) return false;
        if(root->val == value) return true;
        if(dfs(root->left,value,s))
        {
            s+="L";
            return true;
        }
        if(dfs(root->right,value,s))
        {
            s+="R";
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s1 = "",s2 ="";
        dfs(root,startValue,s1);
        dfs(root,destValue,s2);
        // cout << s1 << " " << s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        int m = s2.size();
        int i = 0;
        while(i < n and s1[i] == s2[i])
            i++;
        string ans = "";
        for(int j = i; j < n ;j++)
            ans+="U";
        for(int j = i; j < m;j++)
            ans+=s2[j];
        return ans;
    }
};