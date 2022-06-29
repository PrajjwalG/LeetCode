class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto num: nums)
            sum+=num;
        if(sum%2 == 1) return false;
        sum/=2;
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
        for(int i =1; i <=n;i++)
            dp[i][0] = true;
        for(int i = 1; i <=n;i++)
        {
            for(int j = 1;j <=sum;j++)
            {
                if(j >= nums[i-1])
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    
                }
            }
        }
        return dp[n][sum];   
    }
};