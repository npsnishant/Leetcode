class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> st;
        
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.size() == 0){
                mp[nums2[i]] = -1;
            }
            else if(st.size()>0 && st.top()>nums2[i]){
                mp[nums2[i]] = st.top();
            }
            else if(st.size()>0 && st.top()<=nums2[i]){
                while(st.size()>0 && st.top()<=nums2[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    mp[nums2[i]] = -1;
                }
                else{
                    mp[nums2[i]] = st.top();
                }
            }
            
            st.push(nums2[i]);
        }
        
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            int ans = mp[nums1[i]];
            v.push_back(ans);
        }
        
        return v;
        
    }
};