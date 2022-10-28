class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int i = 0;
        while(i < n - 2)
        {
            int lo = i+1;
            int hi = n-1;
            while(lo < hi)
            {
                if(nums[i] + nums[lo] + nums[hi] < 0 )
                    lo++;
                else if(nums[i] + nums[lo] + nums[hi] > 0)
                    hi--;
                else
                {
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo < hi and nums[lo] == nums[lo+1])
                        lo++;
                    while(lo < hi and nums[hi] == nums[hi-1])
                        hi--;
                    lo++;
                    hi--;
                }
                
            }
            while(i < n-2 and nums[i] == nums[i+1])
                    i++;
                i++;
        }
        
        return ans;
    }
};