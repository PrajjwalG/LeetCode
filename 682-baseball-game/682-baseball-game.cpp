class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        
        
        for(int i = 0; i < ops.size();i++){
            
            if(ops[i] == "C"){
                stk.pop();
            }
            else if(ops[i] =="D"){
                stk.push(2*stk.top());
            }
            
            else if(ops[i] == "+"){
                
                int a = stk.top();
                stk.pop();
                int b = a+stk.top();
                stk.push(a);
                stk.push(b);
            }
            
            else {
                
                int c = stoi(ops[i]);
                stk.push(c);
            }
        }
        int sum = 0;
        while(!stk.empty()){
            
            sum+=stk.top();
            stk.pop();
        }
        return sum;
    }
};