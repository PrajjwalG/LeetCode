class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> res;
        for(auto word : wordDict)
        {
            if(s.substr(0,word.size()) == word)
            {
                if(word.size() == s.size())
                    res.push_back(word);
                else
                {
                    vector<string> temp = wordBreak(s.substr(word.size()),wordDict);
                    for(auto t : temp)
                    {
                        res.push_back(word + " " + t);
                    }
                        
                }
            }
        }
        return res;
    }
};