class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int p = 1;
        int v = 1;
        for(int i = 1; i < n;i++)
        {
            if(nums[i] > nums[i-1])
                p = v+1;
            else if(nums[i] < nums[i-1])
                v = p+1;
        }
        return max(p,v);
    }
};