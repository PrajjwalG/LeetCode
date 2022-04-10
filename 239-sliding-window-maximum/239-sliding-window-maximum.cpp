class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int,greater<int>> mp;
        for(int i = 0; i < k;i++)
            mp[nums[i]]++;
        vector<int> out;
        int n = nums.size();
        out.push_back(mp.begin()->first);
        for(int i = k;i < n;i++)
        {
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0)
                mp.erase(nums[i-k]);
            mp[nums[i]]++;
            out.push_back(mp.begin()->first);
        }
        
        
        return out;
    }
};