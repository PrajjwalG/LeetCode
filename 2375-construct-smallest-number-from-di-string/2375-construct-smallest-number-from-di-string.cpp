class Solution
{
public:
    string reverse(string str, int s, int n)
    {
        int e = s + n;
        while (s <= e)
        {
            swap(str[s], str[e]);
            s++, e--;
        }
        return str;
    }
    string smallestNumber(string s)
    {
        string str = "";
        for (int i = 1; i <= s.length() + 1; i++)
        {
            str += to_string(i);
        }
        vector<int> v;
        for (int i = 0; i < s.length();)
        {
            int count = 0;
            if (s[i] == 'D')
            {
                while (i < s.length() && s[i] == 'D')
                {
                    count++;
                    i++;
                }
                v.push_back(count);
            }
            else
            {
                i++;
            }
        }

        int j = 0;
        for (int i = 0; i < s.length();)
        {
            if (i < s.length() && s[i] == 'D')
            {
                str = reverse(str, i, v[j]);
                i += v[j];
                j++;
            }
            else if (i < s.length() && s[i] == 'I')
            {
                i++;
            }
        }

        return str;
    }
};