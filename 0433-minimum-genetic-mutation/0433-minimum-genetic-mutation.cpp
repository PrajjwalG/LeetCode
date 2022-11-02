class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> vis, dict;
        for(auto b:bank)
            dict.insert(b);
        if(dict.find(end) == dict.end()) return -1;
        int ans = 0;
        vector<char> gene = {'A','C','G','T'};
        
        queue<string> q;
        q.push(start);
        vis.insert(start);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string temp = q.front();
                q.pop();
                if(temp == end) return ans;
                for(int i = 0; i < 8;i++)
                {
                    auto orig = temp[i];
                    
                    for(int j = 0; j < 4;j++)
                    {
                        temp[i] = gene[j];
                        if(dict.find(temp)!=dict.end())
                        {
                            if(vis.find(temp) == vis.end())
                            {
                                q.push(temp);
                                vis.insert(temp);
                            }
                        }
                    }
                    temp[i] = orig;
                }
            }
            ans++;
        }
        
        return -1;
    }
};