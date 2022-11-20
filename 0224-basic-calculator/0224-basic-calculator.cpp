class Solution {
public:
    int calculate(string s) {
        
        int ans = 0;
        long long curr = 0,sign = 1;
        stack<int> nums;
        
        for(auto c: s)
        {
            if(isdigit(c))
            {
                curr = curr*10 + c-'0';
            }
            
            else if(c == '+')
            {
                ans+=curr*sign;
                curr = 0;
                sign = 1;
            }
            
            else if(c == '-')
            {
                ans+=curr*sign;
                curr = 0;
                sign = -1;
            }
            else if(c == '(')
            {
                nums.push(ans);
                nums.push(sign);
                ans = 0;
                sign = 1;
            }
            
            else if(c == ')')
            {
                ans += curr*sign;
                curr = 0;
                ans*=nums.top();
                nums.pop();
                ans+=nums.top();
                
                nums.pop();
            }
        }
        
        ans+=curr*sign;
        return ans;
    }
};