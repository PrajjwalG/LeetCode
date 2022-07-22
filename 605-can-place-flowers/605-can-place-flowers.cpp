class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int i = 0;
        int k = f.size();
        while(i < k and n!=0)
        {
            if(f[i] == 1)
            {
                i+=2;
            }
            else
            {
                if(i!= k-1 and f[i+1] == 1)
                {
                    i+=3;
                }
                else
                {
                    n--;
                    i+=2;
                }
            }
            cout << i << " ";
        }
        return n == 0;
    }
};