class Solution {
   static bool cmpr(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>> plant;
        int n = plantTime.size();
        for(int i = 0; i < n;i++)
        {
            plant.push_back({growTime[i],plantTime[i]});
        }
        
        sort(plant.begin(),plant.end(),cmpr);
        int days = 0;
        int grow = 0;
        for(auto it: plant)
        {
            days +=it.second;
            grow = max(grow,days + it.first);
        }
        
        return grow;
        
    }
};