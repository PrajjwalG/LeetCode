class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n,0);
        priority_queue<pair<int,int>> pq;
        
        for(int i = n-1;i>=0;i--)
        {
            while(pq.size() and pq.top().second > i+k)
                pq.pop();
            sum[i] = nums[i];
            sum[i]+=pq.size()?pq.top().first:0;
            pq.push({sum[i],i});
        }
        return sum[0];
    }
};