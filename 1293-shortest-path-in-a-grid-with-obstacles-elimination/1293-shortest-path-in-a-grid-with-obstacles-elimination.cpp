class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int k)
    {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        
        queue<vector<int>> q;
        q.push({0,0,0,k});
        int ans = INT_MAX;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int x = node[0];
            int y = node[1];
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
		
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return node[2];
            
            if(grid[x][y] == 1)
            {
                if(node[3] > 0)
                    node[3]--;
                else continue;
            }
            if(vis[x][y] != -1 and vis[x][y] >=node[3])
                continue;
            vis[x][y] = node[3];
            
            
            q.push({x+1,y,node[2]+1,node[3]});
            q.push({x,y+1,node[2]+1,node[3]});
            q.push({x-1,y,node[2]+1,node[3]});
            q.push({x,y-1,node[2]+1, node[3]});
        }
        
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
};