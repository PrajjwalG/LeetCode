class Solution {
public:
    int dp[101][101];
    bool dfs(string s1, string s2,string s3, int i, int j)
    {
        if(i == s1.size() and j == s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i < s1.size() and s1[i] == s3[i+j] and dfs(s1,s2,s3,i+1,j))
            return true;
        if(j < s2.size() and s2[j] == s3[i+j] and dfs(s1,s2,s3,i,j+1))
            return true;
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(),n = s2.size(), N = s3.size();
        if(m+n!=N) return false;
        memset(dp,-1,sizeof(dp));
        
        return dfs(s1,s2,s3,0,0);
    }
};