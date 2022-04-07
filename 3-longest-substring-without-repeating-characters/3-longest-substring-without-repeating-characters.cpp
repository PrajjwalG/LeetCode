class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() ==0) return 0;
        int n = s.size();
        unordered_map<char,int> a;
        deque<char> dq;
        int m = 1;
        for(int i = 0; i < n;i++)
        {
            if(a[s[i]%97] == 0)
            {
                dq.push_back(s[i]);
                a[s[i]%97]++;
            }
            else
            {
                m = max(m,(int)dq.size()); 
                while(dq.front()!=s[i])
                {
                    a[dq.front()%97]--;
                    dq.pop_front();
                }
                dq.pop_front();
                dq.push_back(s[i]);
            }
        }
        m = max(m,(int)dq.size());
        return m;
        }
};
