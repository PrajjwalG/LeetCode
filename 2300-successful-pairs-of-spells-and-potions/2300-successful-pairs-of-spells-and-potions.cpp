class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i = 0; i < spells.size();i++)
        {
            double r = (double)success/spells[i];
            auto it = lower_bound(potions.begin(),potions.end(),r);
            // if(it!=potions.end() and *it == r)it++;
            ans.push_back(potions.size() - (it-potions.begin()));
        }
        return ans;
    }
};