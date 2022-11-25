class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        int sum = 0;
        int n = arr.size();
        vector<int>dp(n,0);
        for(int i = 0; i < n;i++ )
        {
            while(!stk.empty() and arr[stk.top()] >= arr[i])stk.pop();
            
            if(stk.size())
            {
                int prev = stk.top();
                dp[i] = dp[prev] + (i-prev)*arr[i]; 
            }
            
            else
            {
                dp[i] = (i+1)*arr[i];
            }
            sum = (sum+dp[i])%mod;
            stk.push(i);
        }
        return sum;
    }
};