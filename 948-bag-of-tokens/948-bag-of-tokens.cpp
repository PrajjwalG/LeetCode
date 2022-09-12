class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int start=0, end= tokens.size()-1;
        int score=0; int m=0;
        while(start<=end)
        {
          if(power >= tokens[start]) 
          {  
                power -= tokens[start];
                score++;
                m=max(m, score);
                start++;
          }
            
          else if(score>=1)
          {
                power += tokens[end];
                score --;
                end--;
          }
          else
               break;
        
        
        }
        
        return m;
    }
};