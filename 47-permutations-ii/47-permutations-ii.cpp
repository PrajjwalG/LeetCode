class Solution {
public:
    void solve(int i, vector<int>& nums, set<vector<int>>& res)
    {
        if(i == nums.size())
        {
            res.insert(nums);
            return;
        }
        for(int j = i; j < nums.size();j++)
        {
            if(i == j or nums[i]!=nums[j])
            {
                swap(nums[i],nums[j]);
                solve(i+1,nums,res);
                swap(nums[i],nums[j]);
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        
        solve(0,nums,res);
        vector<vector<int>> ans (res.begin(),res.end());
        return ans;
    }
};