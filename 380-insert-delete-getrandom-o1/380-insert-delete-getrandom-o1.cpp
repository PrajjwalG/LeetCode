class RandomizedSet {
public:
    vector<int> dp;
    unordered_map<int,int> idx;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(idx.count(val)) return false;
        idx[val] = dp.size();
        dp.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!idx.count(val)) return false;
        int removeidx = idx[val];
        int lastidx = dp.size() - 1;
        int num = dp[lastidx];
        swap(dp[removeidx],dp[lastidx]);
        idx[num] = removeidx;
        idx.erase(val);
        dp.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = dp.size();
        return dp[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */