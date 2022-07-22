class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        int Max = -1;
        for(int i = 0 ; i < n;i++)
        {
            Max = max(Max,arr[i]);
            if(Max == i)
            {
                count++;
                Max = -1;
            }
        }
        return count;
    }
};