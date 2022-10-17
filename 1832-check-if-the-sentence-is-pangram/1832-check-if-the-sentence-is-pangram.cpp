class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        if(n < 26) return false;
        int l = 26;
        vector<int> a(26,0);
        for(int i = 0; i < n;i++)
        {
            if(a[sentence[i] - 'a'] == 0)
            {
                l--;
                a[sentence[i]-'a']++;
            }
            if(l == 0) return true;
        }
        
        return false;
    }
};