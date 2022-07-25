class Solution {
public:
    
    int dp[21][21];
    
    int solve(int i, int j, int n, vector<int> nums){
        if(i<0 || i>=n || j<0 || j>=n || i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int option1 = min(solve(i+2, j, n, nums), solve(i+1, j-1, n, nums));
        int option2 = min(solve(i, j-2, n, nums), solve(i+1, j-1, n, nums));
        dp[i][j] = max(nums[i]+option1, nums[j]+option2);
        return dp[i][j];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        
        int first = solve(0, nums.size()-1, nums.size(), nums);
        if(first>=sum-first){
            return true;
        }
        else{
            return false;
        }
    }
};