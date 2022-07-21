class Solution {
public:
    
    int digitSum(int n){
        int a = n;
        int sum = 0;
        while(n){
            a = n%10;
            sum = sum + a;
            n = n/10;
        }
        
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i=0;i<nums.size();i++){
            int sum = digitSum(nums[i]);
            v.push_back({sum, nums[i]});
        }
        
        sort(v.begin(), v.end());
        int ans = -1;
        for(int i=1;i<v.size();i++){
            if(v[i].first == v[i-1].first){
                ans = max(ans, v[i].second + v[i-1].second);
            }
        }
        
        return ans;
    }
};