class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int res = 0;
        for(string w:words)
        {
            string temp = w;
            reverse(temp.begin(),temp.end());
            if(mp[temp]>0)
            {
                res+=4;
                mp[temp]--;
            }
            
            else
            {
                mp[w]++;
            }
        }
        
        for(auto it: mp)
        {
            if(it.first[0] == it.first[1] and it.second > 0)
            {
                res+=2;
                break;
            }
                
        }
        
        return res;
    }
};