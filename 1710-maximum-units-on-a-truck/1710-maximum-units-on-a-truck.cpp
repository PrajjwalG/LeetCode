class Solution {
public:
    static bool cmpr(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmpr);
        int weight = 0;
        int t;
        for(int i = 0; i < boxTypes.size();i++)
        {
            if(truckSize<=0) break;
            t = min(truckSize,boxTypes[i][0]);
            weight+= t*boxTypes[i][1];
            truckSize-=t;
            
        }
        return weight;
    }
};