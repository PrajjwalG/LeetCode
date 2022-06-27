class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int num1;
        int num2;
        for(int i = 0; i < tokens.size();i++)
        {
            if(tokens[i] == "*")
            {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1*num2);
            }
            else if(tokens[i] == "/")
            {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1/num2);
            }
            else if(tokens[i] == "-")
            {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
                stk.pop();
                stk.push(num1-num2);
            }
            else if(tokens[i] == "+")
            {
                num2 = stk.top();
                stk.pop();
                num1 = stk.top();
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