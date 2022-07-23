class Solution {
public:
    
    int dp[51][51][51];
    int mod = 1000000007;
    
    int solve(int n, int m, int maxmove, int row, int col){
        if(row<0 || row>=n || col<0 || col>=m){
            return 1;
        }
        
        if(maxmove == 0){
            return 0;
        }
        
        if(dp[row][col][maxmove]!=-1){
            return dp[row][col][maxmove];
        }
        
        int ans = 0;
        //up
        ans = (ans + solve(n, m, maxmove-1, row-1, col))%mod;
        //down
        ans = (ans + solve(n, m, maxmove-1, row+1, col))%mod;
        //left
        ans = (ans + solve(n, m, maxmove-1, row, col-1))%mod;
        //right
        ans = (ans + solve(n, m, maxmove-1, row, col+1))%mod;
        
        return dp[row][col][maxmove] = ans%mod;

        
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(n, m, maxMove, startRow, startColumn);
    }
};