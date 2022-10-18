class Solution {
public:
    string countAndSay(int n) {
        
        string say = "11";
        if(n == 1) return "1";
        for(int i = 3; i <= n;i++)
        {
            int count = 1;
            string k = "";
            for(int j = 0; j < say.size()-1;j++)
            {
                if(say[j] == say[j+1])
                    count++;
                else if(say[j]!=say[j+1])
                {
                    k = k + to_string(count) + say[j];
                    count = 1;
                }
                
            }
            k = k + to_string(count) + say[say.size() - 1];
            say = k;
        }
        return say;
    }
};