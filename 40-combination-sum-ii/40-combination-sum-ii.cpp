class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates,int target, vector<int>& temp, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        while(i < candidates.size() and target - candidates[i] >=0)
        {
            temp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],temp,++i);
            temp.pop_back();
            while(i < candidates.size() and candidates[i] == candidates[i-1])
            {
                i++;
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        int i = 0;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,temp,i);
        
        return ans;
    }
};