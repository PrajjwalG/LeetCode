class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k) == mp.end())mp[sum%k] = i;
            else if( i - mp[sum%k] >=2) return true;
            if(sum%k == 0 and i>=1) return true;
        }
        return false;
    }
};