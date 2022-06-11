class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        int count = 0;
        for(int i = 0; i < n;i++)
        {
            if(nums[i] == 0)
            {
                m = max(m,count);
                count = 0;
            }
            else
                count++;
        }
        m = max(m,count);
        return m;
    }
};