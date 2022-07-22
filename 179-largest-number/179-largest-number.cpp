class Solution {
public:
    
    // if cmp return false then this tells us that “first” argument should not be 
    // placed before “second” argument
    static bool cmp(string &s1, string &s2){
        return s1+s2<s2+s1;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        
        sort(v.begin(), v.end(), cmp);
        
        string str = "";
        for(int i=v.size()-1;i>=0;i--){
            str = str + v[i];
        }
        
        if(str[0] == '0'){
            return "0";
        }
        return str;
    }
};