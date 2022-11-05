class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-2;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(mid%2)
            {
                if(nums[mid] != nums[mid-1])
                {
                    right = mid-1;
                }
                else
                    left = mid+1;
            }
            else
            {
                if(nums[mid]!=nums[mid+1])
                {
                    right = mid-1;
                }
                else left = mid+1;
            }
        }
        
        return nums[left];
    }
};