class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<int> out;
        while(i < n && nums[i]<0)
            i++;
        int k = i-1;
        while(k>=0 && i < n)
        {
            if(abs(nums[i]) <=abs(nums[k]))
            {
                out.push_back(nums[i]*nums[i]);
                i++;
            }
            else
            {
                out.push_back(nums[k]*nums[k]);
                k--;
            }
        }
        while(k>=0)
        {
            out.push_back(nums[k]*nums[k]);
            k--;
        }
        
        while(i < n)
        {
            out.push_back(nums[i]*nums[i]);
            i++;
        }
        return out;
    }
};