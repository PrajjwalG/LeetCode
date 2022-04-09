class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> umap;
        vector<vector<int>> num_feq_map; 
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            umap[nums[i]]++;
        }
                
        for(auto i= umap.begin(); i!=umap.end(); i++){
            vector<int> temp;
            temp.push_back(i->second);
            temp.push_back(i->first);    
            num_feq_map.push_back(temp);
        }
        sort(num_feq_map.begin(), num_feq_map.end());
        
        for(int i=0; i<k; i++){
            ans.push_back(num_feq_map[num_feq_map.size()-1-i][1]);
        }
       
        return ans;
    }
};