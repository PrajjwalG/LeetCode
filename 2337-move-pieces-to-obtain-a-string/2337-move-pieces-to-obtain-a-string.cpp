class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0;
        int j = 0;
        int count_s = 0;
        int count_tg = 0;
        if(start.size()!=target.size()) return false;
        while(i < start.size() or j < target.size())
        {
            while(i < start.size() and start[i] == '_')
            {
                i++;
                count_s++;
            }
            while(j < target.size() and target[j] == '_')
            {
                j++;
                count_tg++;
            }
            // cout << start[i] << target[j];
            if(start[i] == 'L' and target[j] == 'L' and i < j)
                return false;
            // cout << 1;
            if(start[i] == 'R' and target[j] == 'R' and j < i)
                return false;
            // cout << 2;
            if(start[i]!=target[j])
                return false;
            // cout << 3;
            ++i;
            ++j;
            
        }
        // cout << count_s << count_tg;
        return count_s == count_tg;
    }
};