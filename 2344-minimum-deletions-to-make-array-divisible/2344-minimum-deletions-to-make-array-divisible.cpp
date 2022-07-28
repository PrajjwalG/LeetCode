class Solution {
public:
    // int gcd(int a, int b)
    // {
    //     return b == 0 ? a : gcd(b,a%b);
    // }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int g = numsDivide[0];
        sort(nums.begin(),nums.end());
        for(int i = 1; i < numsDivide.size();i++)
        {
            g = __gcd(g,numsDivide[i]);
        }
        for(int i = 0; i < nums.size();i++)
        {
            if(g%nums[i] == 0)
                return i;
        }
        return -1;
    }
};