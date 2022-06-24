class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int count = 1;
        int i;
        for( i = 1; i < nums.size();i++)
        {
            if(nums[i] == nums[i-1]) continue;
            else count++;
            if(count == 3) break;
        }
        if(count!=3) return nums[0];
        return nums[i];
    }
};