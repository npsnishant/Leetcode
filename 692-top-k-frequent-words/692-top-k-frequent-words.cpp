class Solution {
public:
    
     struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v;
        map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;

        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        for(auto x:mp){
            pq.push({x.second, x.first});
        }
        
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        // sort(v.begin(), v.end());
        return v;
    }
};