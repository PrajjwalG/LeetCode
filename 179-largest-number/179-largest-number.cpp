class Solution {
public:
    static bool cmpr(int& a, int & b)
    {
        string num1 = to_string(a);
        string num2 = to_string(b);
        return num1+num2 > num2 + num1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmpr);
        string s = "";
        int i = 0;
        for(auto num:nums) 
        {
            if(num == 0) i++;
            s+=to_string(num);
        }
        if(i == s.size()) return "0";
        return s;
    }
};