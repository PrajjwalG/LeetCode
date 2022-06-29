class Solution {
public:
    static bool cmpr(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmpr);
        // return people;
        vector<vector<int>> ans;
        int n = people.size();
        for(int i = 0; i < n;i++)
        {
            ans.insert(ans.begin() + people[i][1],people[i]);
        }
        return ans;
    }
};