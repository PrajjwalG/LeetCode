class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        if(nums.size() == 0) return 0;
        for(int i = 0; i < nums.size();i++)
            mp[nums[i]]++;
        int count = 1;
        int Max = 1;
        for(auto it = ++mp.begin();it!=mp.end();it++)
        {
            auto temp = it;
            if((--temp)->first + 1 == it->first)
                count++;
            else
            {
                Max = max(count,Max);
                count = 1;
            }
            // cout << it->first << " ";
        }
        Max = max(count,Max);
        return Max;
    }
};