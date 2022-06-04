class Solution {
public:

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        map<vector<int>,int> mp;
        for(int i = 0; i < queens.size();i++)
            mp[queens[i]]++;
        int kx = king[0];
        int ky = king[1];
        int row = kx;
        int col = ky;
        while(row>=0)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            row--;
        }
        row = kx;
        while(row>=0 && col >=0)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            row--;
            col--;
        }
        row = kx;
        col = ky;
        while(col >=0)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            col--;
        }
        row = kx;
        col = ky;
        while(row<8)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            row++;
        }
        row = kx;
        col = ky;
        while(row<8 && col <8)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            row++;
            col++;
        }
        row = kx;
        col = ky;
        while(col <8)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            col++;
        }
        row = kx;
        col = ky;
        while(row>=0 && col<8)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            row--;
            col++;
        }
        row = kx;
        col = ky;
        while(row<8 && col >=0)
        {
            if(mp[{row,col}]>0)
            {
                ans.push_back({row,col});
                break;
            }
            row++;
            col--;
        }
        
        return ans;
    }
};