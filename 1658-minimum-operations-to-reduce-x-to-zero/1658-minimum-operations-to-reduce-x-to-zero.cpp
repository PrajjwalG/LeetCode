class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(auto num:nums)
            total+= num;
        if(total < x) return -1;
        if(total ==x ) return nums.size();
        total -=x;
        int m = -1;
        int sum = 0;
        int left = 0;
        for(int right = 0; right < nums.size();right++)
        {
            sum+=nums[right];
        
             while(sum >=total)
             {
                 if(sum == total)m = max(right-left+1,m);
                 sum-=nums[left];
                 left++;
             }
            
        }
        if(m ==-1) return -1;
        
        return nums.size()-m;
    }
};