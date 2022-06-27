class Solution {
public:

    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1 ; i <=sqrt(n);i++)
        {
            nums.push_back(i*i);
        }
        int k = nums.size();
        int dp[k][n+1];
        for(int i = 0; i < k;i++)
            dp[i][0] = 0;
        for(int i = 1; i <=n;i++)
            dp[0][i] = i;
        for(int i = 1; i < k;i++)
        {
            for(int j = 1; j <=n;j++)
            {
                if(nums[i] > j)dp[i][j] = min(j,dp[i-1][j]);
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-nums[i]] + 1);
                }
            }
        }
        // for(int i = 0; i < k;i++)
        // {
        //     for(int j = 0; j<=n;j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }cout << endl;
        // }
        return dp[k-1][n];
    }
};