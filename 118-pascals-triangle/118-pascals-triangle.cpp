class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pascal;
        for(int i = 0; i < numRows;i++)
        {
            vector<int>temp;
            for(int j = 0; j < i+1;j++)
            {
                if(j == 0 || j == i)
                    temp.push_back(1);
                else
                {
                    temp.push_back(pascal[i-1][j] + pascal[i-1][j-1]);
                }
            }
            pascal.push_back(temp);
        }
        return pascal;
    }
};