class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val))
        {
            int idx = mp[val];
            int temp = nums.back();
            nums[idx] = temp;
            nums.pop_back();
            mp[temp] = idx;
            mp.erase(val);
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        int idx = rand()%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */