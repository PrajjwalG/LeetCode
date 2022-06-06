class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int i = 0;
        sort(nums.begin(),nums.end());
        int start = 0;
        int next = 0;
        while(next < n)
        {
            while(next < n && nums[next]-nums[start]<=k) next++;
            start = next;
            res++;
        }
        return res;
    }
};