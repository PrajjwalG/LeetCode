class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_small(n,0);
        vector<int> right_small(n,n-1);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < n;i++)
        {
            while(!stk.empty() &&heights[stk.top()] >= heights[i])
                stk.pop();
            if(!stk.empty())
                left_small[i] = stk.top()+1;
            stk.push(i);
            
        }
        while(!stk.empty())
            stk.pop();
        stk.push(n-1);
        for(int i = n-2;i>=0;i--)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(!stk.empty())
                right_small[i] = stk.top() -1;
            stk.push(i);
        }
        int Max = 0;
        for(int i = 0; i < n;i++)
        {
            Max = max(Max,(right_small[i] - left_small[i] + 1)*heights[i]);
        }
        return Max;
    }
};