class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x1) {
        priority_queue<pair<int, int>> pq;
        for(auto x: arr){
            // pq.push(abs(x1-x));
            pq.push({(abs(x1-x)), x});
            if(pq.size()>k){
                // cout<<pq.top().second<<endl;
                pq.pop();
            }

        }
        vector<int> res;
        while(pq.size()){
            // cout<<;
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
