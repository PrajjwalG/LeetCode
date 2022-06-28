class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>mp;
        vector<int> nums(26,0);
        for(int i = 0; i < s.size();i++)
        {
            nums[s[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26;i++)
        {
            if(nums[i] == 0) continue;
            while(mp[nums[i]]!=0 and nums[i]!=0)
            {
                nums[i]--;
                count++;
            }
            mp[nums[i]]++;
        }
        return count;
    }
};