class Solution {
public:
    bool Subseq(string s,string x,int m, int n)
    {
        int j = 0;
        for(int i = 0; i < m and j < n;i++)
        {
            if(s[i] == x[j])j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string,bool> mp;
        for(auto word:words)
        {
            if(mp.find(word) !=mp.end())
            {
                if(mp[word] == true)
                    count++;
                
                continue;
            }
            mp[word] = Subseq(s,word,s.size(),word.size());
            if(mp[word] == true)
                count++;
        }
        return count;
    }
};