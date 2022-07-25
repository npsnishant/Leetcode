class Solution {
public:
    
    static bool cmp(const vector<int> &v1, const vector<int> &v2){
        return v1[1]<v2[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        // first method by dp LIS
//         int n = pairs.size();
//         int dp[1001] = {0};
//         dp[0] = 1;
//         int ans = 0;
//         int count = 0;
        
//         sort(pairs.begin(), pairs.end());
//         for(int i=0;i<n;i++){
//             count = 0;
//             for(int j=0;j<i;j++){
//                 if(pairs[i][0]>pairs[j][1]){
//                     count = max(count, dp[j]);
//                 }
//             }
//             dp[i] = count+1;
//             ans = max(ans, dp[i]);
//         }
        
//         // for(int i=0;i<n;i++){
//         //     cout<<dp[i]<<" ";
//         // }
//         return ans;
        
        
        //second method by greedy
        
        sort(pairs.begin(), pairs.end(), cmp);
        // int x = pairs[0][1];
        int x = pairs[0][1];
        int count = 1;
        
        for(int i=1;i<pairs.size();i++){
            if(x<pairs[i][0]){
                x = pairs[i][1];
                count++;
            }
        }
        
        return count;
    }
};