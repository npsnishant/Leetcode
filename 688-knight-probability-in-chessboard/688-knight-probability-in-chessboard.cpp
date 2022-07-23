class Solution {
public:
    double solve(int row, int col, int n, int move, vector<vector<vector<double>>> &dp){
        if(row<0 || row>=n || col<0 || col>=n){
            return 0;
        }
        
        if(move == 0){
            return 1;
        }
        
        if(dp[row][col][move]!=0){
            return dp[row][col][move];
        }
        
        double ans =
            solve(row-2, col+1, n, move-1, dp) + solve(row-1, col+2, n, move-1, dp) +
            solve(row+1, col+2, n, move-1, dp) + solve(row+2, col+1, n, move-1, dp) + 
            solve(row+2, col-1, n, move-1, dp) + solve(row+1, col-2, n, move-1, dp) +
            solve(row-1, col-2, n, move-1, dp) + solve(row-2, col-1, n, move-1, dp);
        
        ans = ans/8;
        return dp[row][col][move] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        // memset(dp, -1, sizeof(dp));
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1)));
        return solve(row, column, n, k, dp);
    }
};