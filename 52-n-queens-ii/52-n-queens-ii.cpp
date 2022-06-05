class Solution {
public:
    bool check(int row, int col,vector<string>& board,int n)
    {
        int drow = row;
        int dcol = col;
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        row = drow;
        col = dcol;
        while(col>=0)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        col = dcol;
        while(row<n && col>=0)
        {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>& ans,vector<string>& board,int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n;row++)
        {
            if(check(row,col,board,n))
            {
                board[row][col] = 'Q';
                solve(col+1,ans,board,n);
                board[row][col] = '.';
            }
            
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i = 0; i < n;i++)
            board.push_back(s);
        solve(0,ans,board,n);
        return ans.size();
    }
};