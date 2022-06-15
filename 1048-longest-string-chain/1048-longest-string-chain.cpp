class Solution {
public:
    static bool cmpr(string& s1, string& s2)
    {
        return s1.size() < s2.size();
    }
    bool check(string& word1, string& word2)
    {
        if(word1.size() != word2.size()+1)
            return false;
        bool flag = true;
        int i = 0,j = 0;
        while(i < word1.size())
        {
            if(word1[i]!=word2[j] and flag)
            {
                i++;
                flag = false;
            }
            else if(word1[i] == word2[j])
            {
                i++;
                j++;
            }
            else
                return false;
            // cout << word1[i] << " " << word2[j] << endl;
        }
        return true;
        
        
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmpr);
        for(auto word:words)
            cout << word << " ";
        cout << endl;
        int n = words.size();
        int dp[n];
        dp[0] = 1;
        for(int i = 1; i <n;i++)
        {
            dp[i] = 0;
            for(int j = 0; j < i;j++)
            {
                bool t = check(words[i],words[j]);
                // cout << t << " ";
                if(t)
                    dp[i] = max(dp[i],dp[j]);
            }
            dp[i]+=1;
            // cout << endl;
        }
        int m = 0;
        for(int i = 0; i < n;i++)
        {
            m = max(m,dp[i]);
            // cout << dp[i] << " ";
        }
            
        return m;
    }
};