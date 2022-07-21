class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int prod = 1;
        int ans = 0;
        
        if(k <= 1){
            return 0;
        }
        
        while(j<nums.size()){
            prod = prod * nums[j];
            while(prod>=k){
                prod = prod/nums[i];
                i++;
            }
            ans = ans + (j-i+1);
            j++;
        }
        
        return ans;
    }
};


//     10 5
//     5 2 6
    
    
//     10 5 5 2 6
//     5 2 
//     2 6
//     5 2 6
    
    
    