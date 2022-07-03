class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for(int i = 0; i < n;i++)
            sum+=(gas[i] - cost[i]);
        if(sum<0) return -1;
        int pos = 0;
        int temp = 0;
        for(int i = 0; i < n-1;i++)
        {
            temp+=(gas[i] - cost[i]);
            if(temp < 0)
            {
                pos = i+1;
                temp = 0;
            }
        }
        return pos;
    }
};