class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        if(n ==1) return 1;
        for(int i = 0; i < n-1; i++)
        {
            if(ratings[i] < ratings[i+1])
                candies[i+1] = candies[i] + 1;
        }
        int sum = 0;
        for(int i = n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1] and candies[i] <= candies[i+1])
                candies[i] = candies[i+1]+1;
            sum+=candies[i];
        }
        sum+=candies[n-1];
        return sum;
    }
};