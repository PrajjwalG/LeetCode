class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = INT_MAX, num2 = INT_MAX;
        int cnt1 = 0, cnt2 = 0;
        for(auto it: nums)
        {
            if(it == num1)
                cnt1++;
            else if(it == num2)
                cnt2++;
            else if(cnt1 == 0)
            {
                num1 = it;
                cnt1++;
            }
            else if(cnt2 == 0)
            {
                num2 = it;
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(auto it: nums)
        {
            if(it == num1)
                cnt1++;
            if(it == num2)
                cnt2++;
        }
        vector<int> ans;
        if(n/3 < cnt1) ans.push_back(num1);
        if(n/3 < cnt2) ans.push_back(num2);
        return ans;
    }
};