class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int num1;
        int num2;
        if(n%2 == 0)
        {
            num1 = ceil(double((nums[n/2] + nums[n/2-1])/2));
            num2 = floor(double((nums[n/2] + nums[n/2-1])/2));
        }
        else
        {
            num1 = nums[n/2];
            num2 = nums[n/2];
        }
        cout << num1 << " " << num2;
        int ans1 = 0;
        int ans2 = 0;
        for(int num:nums)
        {
            ans1+=abs(num - num1);
            ans2+=abs(num-num2);
        }
        return min(ans1,ans2);
    }
};