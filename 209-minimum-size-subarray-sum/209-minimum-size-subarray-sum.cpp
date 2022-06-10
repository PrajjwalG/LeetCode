class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int sum = 0;
        int w = INT_MAX;
        for(int right = 0; right < n;right++)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                w = min(w,right-left+1);
                sum-=nums[left];
                left+=1;
            }
        }
        if(w == INT_MAX) return 0;
        return w;
    }
};