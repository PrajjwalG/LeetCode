class Solution {
public:
    void next(vector<int>& nums)
    {
        int n = nums.size();
        int k,l;
        for(k = n-2;k>=0;k--)
        {
            if(nums[k] < nums[k+1])
            {
                for(l = n-1;l>k;l--)
                {
                    if(nums[l] > nums[k])
                    {
                        swap(nums[l],nums[k]);
                        break;
                    }
                }
                break;
            }
        }
        
        reverse(nums.begin()+k+1,nums.end());
    }
    
    
    int factorial(int n)
    {
        if(n<=1) return n;
        return n*factorial(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n  = factorial(nums.size());
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        for(int i = 0; i < n;i++)
        {
            ans.push_back(nums);
            next(nums);
        }
        
        return ans;
    }
};