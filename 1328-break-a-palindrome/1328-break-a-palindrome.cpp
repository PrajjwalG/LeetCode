
class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        if(n <= 1)
            return "";
            
        for(int i = 0; i < n; i++)
        {
            if(n % 2 && i == n / 2)
                continue;
            
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                break;
            }
        }
        
        if(checkPalindrome(palindrome))
            palindrome[n - 1] = 'b';
        
        return palindrome;
    }
    
    bool checkPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        
        return true;
    }
};