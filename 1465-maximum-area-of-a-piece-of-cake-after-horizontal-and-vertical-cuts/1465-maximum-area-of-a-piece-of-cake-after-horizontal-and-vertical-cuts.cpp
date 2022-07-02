class Solution {
public:
    int maxArea(int height, int width, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long long hmax = h[0];
        
        for(int i = 1; i < h.size();i++)
        {
            hmax = max(hmax,(long long)h[i]-h[i-1]);
        }
        hmax = max((long long)height - h[h.size() - 1],hmax);
        long long vmax = v[0];
        for(int i = 1; i < v.size();i++)
        {
            vmax = max(vmax,(long long)v[i]-v[i-1]);
        }
        vmax = max(vmax,(long long)width - v[v.size() - 1]);
        int mod = 1e9 + 7;
        return hmax*vmax%mod;
    }
};