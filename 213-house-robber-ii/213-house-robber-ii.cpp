class Solution {
public:
    int helper(vector<int>&nums){
          int n=nums.size();
       
          vector<int>dp(n,0);
          dp[0]=nums[0];
          dp[1]=max(nums[0],nums[1]);
          for(int i=2;i<n;i++)
              dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
          return dp[n-1];

        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
         if(n==1) return nums[0];
         if(n==2) return max(nums[0],nums[1]);
        vector<int>nums1(nums);
        nums1.erase(nums1.begin());
        
        
        vector<int>nums2(nums);
        nums2.erase(nums2.end()-1);
      
        return max(helper(nums1),helper(nums2));
        
        
         
    }
};