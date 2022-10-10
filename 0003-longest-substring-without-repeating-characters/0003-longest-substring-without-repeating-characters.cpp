class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.size();
        if(n<=1) return n;
        int curr = -1, ans = 0;
        
        for(int i = 0 ; i < n;i++)
        {
            if(mp.find(s[i])!= mp.end() and mp[s[i]] >=curr)
            {
                curr = mp[s[i]];
            }
            mp[s[i]] = i;
            // cout << curr << " ";
            ans = max(ans,i - curr);
        }
        return max(ans,n-1-curr);
    }
};