class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& e) {
        int yend = grid.size()-1,xend = grid[0].size() -1;
        queue<vector<int>> q;
        
        q.push({e[0],e[1],0});
        
        while(!q.empty())
        {
            
            auto temp = q.front();
            int m = temp[0],n = temp[1],d = temp[2];
            q.pop();
            if(grid[m][n] == '+')
                continue;
            grid[m][n] = '+';
            if(m == 0 or n == 0 or m == yend or n == xend)
            {
                // cout << m << "_" << n << " ";
                if(m!=e[0] or n!=e[1])
                    return d;
            }
            
            d++;
            if(m and grid[m-1][n] == '.')q.push({m-1,n,d});
            if(m!=yend and grid[m+1][n] == '.')q.push({m+1,n,d});
            if(n and grid[m][n-1] == '.')q.push({m,n-1,d});
            if(n!=xend and grid[m][n+1] == '.')q.push({m,n+1,d});
            }
        
        return -1;
    }
};