class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(needle.size() == 0) return -1;
        int i = 0;
        while(i < n)
        {
            if(haystack[i] == needle[0])
            {
                int index = i;
                int j = i;
                int k;
                for(k = 0; k < m;k++)
                {
                    if(haystack[j] != needle[k])
                        break;
                    j++;
                }
                if(k == m) return index;
            }
            
            i++;
        }
        
        return -1;
    }
};