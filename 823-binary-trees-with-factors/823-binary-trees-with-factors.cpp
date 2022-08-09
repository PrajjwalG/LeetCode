class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int mod = 1e9+7;
        unordered_map<int,long> tree;
        tree[arr[0]] = 1;
        for(int i = 1; i < arr.size();i++)
        {
            long count = 1;
            for(auto it: tree)
            {
                int node = it.first;
                if(arr[i]%node == 0 and tree.find(arr[i]/node)!=tree.end())
                {
                    count+=tree[node]*tree[arr[i]/node];
                }
            }
            tree[arr[i]] = count;
        }
        int out = 0;
        for(auto it: tree)
            out = (out + it.second)%mod;
        return out;
    }
};