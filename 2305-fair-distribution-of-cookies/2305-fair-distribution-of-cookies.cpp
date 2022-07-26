class Solution {
public:
    int result = INT_MAX;
    void solve(vector<int>& cookies,int k ,vector<int>& students, int c)
    {
        if(c == cookies.size())
        {
            result = min(result,*max_element(students.begin(),students.end()));
            return;
        }
        
        for(int i = 0; i < k;i++)
        {
            if(students[i] + cookies[c] < result)
            {
                students[i]+=cookies[c];
                solve(cookies,k,students,c+1);
                students[i]-=cookies[c];
            }
            
        }
        return ;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> students(k,0);
        solve(cookies,k,students,0);
        return result;
    }
};