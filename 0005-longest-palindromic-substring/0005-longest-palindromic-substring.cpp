class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        int left = 0,right = 0;
        
        for(int i = 0; i < n;i++)
            dp[i][i] = 1;
        for(int i = 0; i < n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                left = i;
                right = i+1;
            }
            else
            {
                dp[i][i+1] = 0;
            }
        }
        
        for(int gap = 2; gap < n; gap++)
        {
            for(int i = 0; i + gap < n;i++)
            {
                if(s[i] == s[i+gap] and dp[i+1][i+gap-1] == 1)
                {
                    dp[i][i+gap] = 1;
                    if(right - left < gap)
                    {
                        left = i;
                        right = i+gap;
                    }
                    
                }
                else
                {
                    dp[i][i+gap] = 0;
                }
            }
        }
        cout << left << right;
        return s.substr(left,right-left+1);
    }
};