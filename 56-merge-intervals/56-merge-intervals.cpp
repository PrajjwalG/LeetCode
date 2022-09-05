class Solution {
public:
    static bool cmpr(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmpr);
        int lo = intervals[0][0];
        int hi = intervals[0][1];
        vector<vector<int>> ans;
        for(int i = 1; i < intervals.size();i++)
        {
            if(intervals[i][0] <= hi)
                hi = max(hi,intervals[i][1]);
            else
            {
                ans.push_back({lo,hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
        }
        ans.push_back({lo,hi});
        return ans;
    }
};