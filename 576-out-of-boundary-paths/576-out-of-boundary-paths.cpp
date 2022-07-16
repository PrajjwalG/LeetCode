class Solution {
public:
    int dp[51][51][51];
    long long mod = 1e9+7;
    int solve(int m, int n, int maxMove,int i, int j)
    {
        if ( i < 0 || j < 0 || i>=m || j>=n)
        {
            return 1;
        }
        if(maxMove <=0)
        {
            return 0;
        }
        if(dp[i][j][maxMove]!=-1)
        {
            return dp[i][j][maxMove];
        }
        int u = solve(m,n,maxMove - 1,i-1,j);
        int d = solve(m,n,maxMove - 1,i+1,j);
        int l = solve(m,n,maxMove - 1,i,j-1);
        int r = solve(m,n,maxMove - 1,i,j+1);
        
        return dp[i][j][maxMove] = (u%mod + d%mod + l%mod + r%mod)%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        memset(dp,-1,sizeof(dp));
        
        return solve(m,n,maxMove,i,j);
    }
};