class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,set<int>>mp;
        for(int i = 0; i < nums.size();i++)
        {
            mp[nums[i]].insert(i);
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
                
                auto lowB = index.lower_bound(loo);
                auto uppB = index.upper_bound(hii);
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