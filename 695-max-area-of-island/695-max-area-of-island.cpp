class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >=grid.size() || j>=grid[0].size() || !grid[i][j]) return 0;
        
        grid[i][j] = 0;
        return 1 + solve(grid,i+1,j)+solve(grid,i-1,j) + solve(grid,i,j+1) + solve(grid,i,j-1);
    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(grid[i][j])
                {
                   ans = max(ans,solve(grid,i,j)) ;
                }
            }
        }
        return ans;
    }
};