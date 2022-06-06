class Solution {
public:

    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size();i++)
        {
            mp[nums[i]] = i;
        }
        for(auto a:operations)
        {
            mp[a[1]] = mp[a[0]];
            mp[a[0]] = -1;
        }
        for(auto i:mp)
        {
            if(i.second>=0)
            {
                nums[i.second] = i.first;
            }
        }
        return nums;
        
    }
};