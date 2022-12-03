class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto c: s)
            mp[c]++;
        vector<pair<int,char>> word;
        for(auto it:mp)
        {
            word.push_back({it.second,it.first});
        }
        sort(word.begin(),word.end());
        
        string ans;
        
        for(auto w: word)
        {
            while(w.first!=0)
            {
                ans.push_back(w.second);
                w.first--;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};