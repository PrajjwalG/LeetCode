class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i = 1; i < triangle.size();i++)
        {
            for(int j = 0; j < triangle[i].size();j++)
            {
                int a = j-1>=0?triangle[i-1][j-1]:INT_MAX;
                int b =  j < triangle[i-1].size()?triangle[i-1][j]:INT_MAX;
                triangle[i][j]+=min(a,b);
            }
        }
        return *min_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
    }
};