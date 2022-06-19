class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        int n = searchWord.size();
        int l = 0;
        int r = products.size()-1;
        for(int i = 0; i < n;i++)
        {
            char ch = searchWord[i];
            while(l<=r && products[l][i]!=ch)
                l++;
            while(l<=r && products[r][i]!=ch)
                r--;
            vector<string> temp;
            for(int j = l;j< l+min(3,r-l+1);j++)
                temp.push_back(products[j]);
            ans.push_back(temp);
            // cout << l << " " << r << endl;
                
        }
        
        return ans;
    }
};