class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> stk;
        string ans = "";
        for(int i = 0; i <=pattern.size();i++)
        {
            stk.push(i+1);
            
            if(i == pattern.size() or pattern[i] == 'I')
            {
                while(!stk.empty())
                {
                    ans+=to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return ans;
    }
};