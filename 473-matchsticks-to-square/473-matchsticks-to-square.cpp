class Solution {
public:
    int a,b,c,d;
    bool solve(vector<int>& matchsticks,int i)
    {
        if(i == matchsticks.size())
        {
            if(a == 0 and b == 0 and c == 0 and d == 0) return true;
            return false;
        }
        if(matchsticks[i]<=a)
        {
            a-=matchsticks[i];
            if(solve(matchsticks,i+1))return true;
            a+=matchsticks[i];
        }
        if(matchsticks[i]<=b)
        {
            b-=matchsticks[i];
            if(solve(matchsticks,i+1))return true;
            b+=matchsticks[i];
        }
        if(matchsticks[i]<=c)
        {
            c-=matchsticks[i];
            if(solve(matchsticks,i+1))return true;
            c+=matchsticks[i];
        }
        if(matchsticks[i]<=d)
        {
            d-=matchsticks[i];
            if(solve(matchsticks,i+1))return true;
            d+=matchsticks[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        sum/=4;
        a = b = c = d = sum;
        sort(matchsticks.rbegin(),matchsticks.rend());
        return solve(matchsticks,0);
    }
};