class Solution {
public:
    bool isValid(unordered_map<char, int> &key, unordered_map<char, int> &m){
	
	for(auto i : key){
		if(!m.count(i.first) || m[i.first] < key[i.first]) return false;
	}

	return true;
}
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        string ans = "";
        
        // Building key
        unordered_map<char, int> key;
        for(char ch : t) key[ch]++;
        
        // *********************
        
        // Iterating through string "s"
        unordered_map<char, int> m;
        int idx = 0; // maintaing "prev idx" inorder to shorten our string when found potential answer 
        
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            
            // Valid => If "m" contains all characters of "key", So its a potential answer
            // If current hashmap "m" does not contains all characters of "key" map
            bool valid = isValid(key, m);
            if(!valid) continue;
            
            // If we have all characters of "key" map in our current hashmap "m"
            // So start removing characters from previous untill "m" becomes invalid (Invalid => not contain all char of "key")
            while(isValid(key, m)){
                int currStrSize = i - idx + 1;
                
                if(ans == "" || currStrSize < ans.size()){
                    ans = s.substr(idx, i-idx+1);
                }
                
                if(m[s[idx]] > 1) m[s[idx]]--;
                else m.erase(s[idx]);
                
                idx++;
            }
            
        }
        
        return ans;
    }
};