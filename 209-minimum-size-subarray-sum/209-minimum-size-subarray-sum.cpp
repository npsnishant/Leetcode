class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int ans = INT_MAX;
        int sum = 0;
        
        while(j<n){
            sum = sum + arr[j];
            while(sum>=target){
                sum = sum -arr[i];
                ans = min(ans, (j-i+1));
                i++;
            }
            j++;
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};