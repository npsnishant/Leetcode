class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> v;
        int start = 0;
        int end = arr.size()-1;
        while(start<=end){
            if(arr[start]+arr[end] == target){
                v.push_back(start+1);
                v.push_back(end+1);
                return v;
            }
            else if(arr[start]+arr[end]>target){
                end--;
            }
            else{
                start++;
            }
        }
        
        return v;
    }
};