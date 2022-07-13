class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhp;
        for(int i=0;i<points.size();i++){
            int x = points[i][0]; 
            int y = points[i][1];
            int dis = x*x + y*y;
            minhp.push({dis, i});
        }
        
        
        while(k--){
            int idx = minhp.top().second;
            ans.push_back(points[idx]);
            minhp.pop();
        }
        
        return ans;
    }
};