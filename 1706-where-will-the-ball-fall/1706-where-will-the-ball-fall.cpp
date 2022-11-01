class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ans;
        
        for(int i = 0; i < n;i++)
        {
            int k = i;
            for(int j = 0; j < m;j++)
            {
                if((k == 0 and grid[j][k] == -1) or (k == n-1 and grid[j][k] == 1))
                {
                    k = -1;
                    break;
                }
                if(k-1 >=0 and grid[j][k] == -1 )
                {
                    if(grid[j][k-1] == 1)
                    {
                        k = -1;
                         break;
                    }
                    
                    else
                    {
                        k--;
                    }
                }
                
                if(k+1 < n and grid[j][k] == 1 )
                {
                    if(grid[j][k+1] == -1)
                    {
                        k = -1;
                        break;
                    }
                    else
                    {
                        k++;
                    }
                }
                
            }
            ans.push_back(k);
        }
        
        return ans;
    }
};