class Solution {
public:
    static bool cmpr(string& a,string& b)
    {
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmpr);
        string ans = "";
        for(int i = 0; i < words.size();i++)
        {
            if(ans.find(words[i]+"#") == string::npos)
                ans+=words[i]+"#";
        }
        // cout << ans;
        return ans.size();
    }
};