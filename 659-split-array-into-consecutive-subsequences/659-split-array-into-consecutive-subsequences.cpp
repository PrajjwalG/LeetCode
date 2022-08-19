class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,need;
        
        for(auto it: nums) freq[it]++;
        
        for(int n: nums)
        {
            if(freq[n] == 0) continue;
            
            if(need[n] > 0)
            {
                need[n]--;
                freq[n]--;
                
                need[n+1]++;
            }
            else if(freq[n] > 0 and freq[n+1]> 0 and freq[n+2] > 0)
            {
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                
                need[n+3]++;
            }
            else
                return false;
        }
        
        
        return true;
    }
};