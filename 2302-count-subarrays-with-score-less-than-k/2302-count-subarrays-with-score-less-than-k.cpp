class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long count = 0, score = 0, sum = 0;
        // standard sliding windows
        for (int right = 0, left = 0; right < n; right++) {
            // update sum
            sum += nums[right];
            // update score
            score = sum * (right - left + 1);
            // pruning current window if invalid i.e., window score >= k
            while (left <= right && score >= k){
                sum -= nums[left++];
                score = sum * (right - left + 1);
            }
            // update count of all such valid subarray
            if (score < k) count += right - left + 1;
        }
		return count;
    }
};