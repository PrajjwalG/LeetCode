class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>& board,int m, int n)
    {
        if(i>=0 && j>=0 && i<m && j < n && board[i][j] == 'O')
        {
            board[i][j] = 'A';
            dfs(i,j-1,board,m,n);
            dfs(i,j+1,board,m,n);
            dfs(i-1,j,board,m,n);
            dfs(i+1,j,board,m,n);
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(i == 0 || j == 0 || i == m-1 || j == n-1 && board[i][j] == 'O')
                {
                    dfs(i,j,board,m,n);
                }
            }
        }
        
        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};