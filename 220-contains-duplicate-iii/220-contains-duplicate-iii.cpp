class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,vector<int>>mp;
        for(int i = 0; i < nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size();i++)
        {
            auto lo = mp.lower_bound((long long)nums[i] - t);
            auto hi = mp.upper_bound((long long) nums[i] + t);
                
            for(auto it = lo; it!=hi;++it)
            {
                auto &index = it->second;
                int loo = i-k;
                int hii = i+k;
                
                auto lowB = lower_bound(index.begin(),index.end(), loo);
                auto uppB = upper_bound(index.begin(),index.end(), hii);
                for(auto itt = lowB; itt!=uppB;++itt)
                {
                    int m = *itt;
                    if(m!=i and abs(m-i) <=k) return true;
                }
            }
            
        }
        return false;
    }
};