class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int m = n-k;
        int sum = 0;
        int total = 0;
        for(int i = 0 ; i < m;i++)
        {
            sum+=card[i];
        }
        total = sum;
        int minSum = sum;
        for(int i = m ; i < n;i++)
        {
            total+=card[i];
            sum+=card[i];
            sum-=card[i-m];
            minSum = min(sum,minSum);
        }
        return total - minSum;
    }
};