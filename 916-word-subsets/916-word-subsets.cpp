class Solution {
public:
    vector<int> freq(string word)
    {
        vector<int> f(26,0);
        for(int i = 0; i < word.size();i++)
        {
            f[word[i] - 'a']++;
        }
        return f;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> max_freq(26,0);
        for(auto s:words2)
        {
            vector<int> temp = freq(s);
            for(int i = 0; i < 26;i++)
            {
                max_freq[i] = max(max_freq[i],temp[i]);
            }
        }
        
        for(auto s: words1)
        {
            vector<int> f = freq(s);
            bool flag = true;
            for(int i = 0; i < 26;i++)
            {
                if(f[i] < max_freq[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)ans.push_back(s);
        }
        return ans;
    }
};