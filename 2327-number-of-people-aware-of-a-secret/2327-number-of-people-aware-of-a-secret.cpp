class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i = 2; i <=n;i++)
        {
            int last = i-forget;
            int j = i-delay;
            while(j>0 and j >last)
            {
                dp[i] = (dp[i] + dp[j])%mod;
                j--;
            }
        }
        int ans = 0;
        int curr = 0;
        while(curr < forget)
        {
            ans = (ans + dp[n-curr])%mod;
            curr++;
        }
        return ans;
    }
};