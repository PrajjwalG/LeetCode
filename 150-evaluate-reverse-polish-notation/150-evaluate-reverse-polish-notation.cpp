class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for(int i = 0; i < tokens.size();i++)
        {
            if(tokens[i] == "*")
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1*num2);
            }
            else if(tokens[i] == "/")
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1/num2);
            }
            else if(tokens[i] == "-")
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1-num2);
            }
            else if(tokens[i] == "+")
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(num1+num2);
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};