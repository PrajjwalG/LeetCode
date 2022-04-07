class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int j = 0;
        int n = intervals.size();
        
        while(j < n && intervals[j][0] < newInterval[0])
            j++;
        intervals.insert(intervals.begin()+j,newInterval);
        vector<vector<int>> out;
        int lo = intervals[0][0];
        int hi = intervals[0][1];
        for(int i = 1; i < n+1;i++)
        {
            if(intervals[i][0]<=hi)
                hi = max(hi,intervals[i][1]);
            
            else
            {
                out.push_back({lo,hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
        
        }
        out.push_back({lo,hi});
        return out;
    }
};