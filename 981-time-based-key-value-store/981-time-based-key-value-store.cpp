class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        string res;
        int low = 0, high = mpp[key].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mpp[key][mid].first <= timestamp) {
                res = mpp[key][mid].second;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return res;
    }
};