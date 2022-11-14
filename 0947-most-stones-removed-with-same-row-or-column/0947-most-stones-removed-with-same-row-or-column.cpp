class Solution {
public:
    bool check(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0] or a[1] == b[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>>& stones, vector<bool> & vis, int idx)
    {
        vis[idx] = true;
        
        for(int i = 0; i < stones.size();i++)
        {
            if(vis[i]) continue;
            if(check(stones[i],stones[idx])) dfs(stones,vis,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n,false);
        int count = 0;
        for(int i = 0; i < n;i++)
        {
            if(vis[i]) continue;
            dfs(stones,vis,i);
            count++;
        }
        
        return n- count;
    }
};