class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int ans;
        while(i < n)
        {
            if(nums[i] == i+1)
                i++;
            else
            {
                if(nums[i] == nums[nums[i]-1])
                {
                    ans = nums[i];
                    break;
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return ans;
    }
};