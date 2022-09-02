class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n-2;
        while(k>=0 and nums[k] >= nums[k+1])
        {
            k--;
        }
        int l;
        if(k!= -1)
        {
            for(int i = n-1;i>=k;i--)
            {
                if(nums[i] > nums[k])
                {
                    l = i;
                    break;
                }
            }

            swap(nums[l],nums[k]);
        }
        
        reverse(nums.begin()+k+1,nums.end());
    }
};