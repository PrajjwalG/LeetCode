class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        int n = numbers.size();
        int k;
        int m;
        for(int i = 0; i < n;i++)
        {
            
            auto it = mp.find(target-numbers[i]);
            if(it!=mp.end())
            {
                 k = min(i+1,it->second+1);
                 m = max(i+1,it->second+1);
                 break;
            }


            
            mp[numbers[i]] = i;
        }
        
        return {k,m};
    }
};