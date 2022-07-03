class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<pair<vector<int>,vector<int>>> wiggle;
        wiggle.push_back({{1,0},{1,1}});
        int lo;
        int hi;
        for(int i = 1; i < nums.size();i++)
        {
            int n = wiggle.size();
            lo = 0;
            hi = 0;
            for(int j = 0; j < n;j++)
            {
                if(wiggle[j].second[1] == 1 and nums[j] > nums[i])
                    lo = max(lo,wiggle[j].second[0]);
                if(wiggle[j].first[1] == 0 and nums[j] < nums[i])
                    hi = max(hi,wiggle[j].first[0]);
            }
            lo++;
            hi++;
            wiggle.push_back({{lo,0},{hi,1}});
        }
        int ans = 0;
        for(int i = 0; i < wiggle.size();i++)
        {
            ans = max({ans,wiggle[i].first[0],wiggle[i].second[0]});
        }
        return ans;
    }
};