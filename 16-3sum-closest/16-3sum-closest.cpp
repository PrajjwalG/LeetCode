class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int dist = INT_MAX;
        int ans[3];
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i < n-2;i++)
        {
            int lo = i+1;
            int hi = n-1;
            
            while(lo<hi)
            {
                int res = dist;
                dist = min(dist,abs(target-nums[i]-nums[lo] - nums[hi]));
                if(res!=dist)
                {
                    ans[0] = nums[i];
                    ans[1] = nums[lo];
                    ans[2] = nums[hi];
                }
                
                if(target - nums[i] - nums[lo] - nums[hi] == 0)
                    return target;
                else if(target > nums[i]+nums[lo] + nums[hi])
                    lo++;
                else
                    hi--;
                
            }
        }
        
        return ans[0] + ans[1] + ans[2];
    }
};