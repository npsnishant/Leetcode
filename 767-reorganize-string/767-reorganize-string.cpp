class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        int capacity = (s.size()+1)/2;
        for(auto x:mp){
            if(x.second>capacity){
                return "";
            }
        }
        
        string str = "";
        
        priority_queue<pair<int, char>> pq;
        for(auto x:mp){
            pq.push({x.second, x.first});
        }        
        
        
        while(pq.size()>1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            str = str + top1.second;
            str = str + top2.second;
            top1.first--;
            top2.first--;
            
            if(top1.first>0){
                pq.push(top1);    
            }
            if(top2.first>0){
                pq.push(top2);
            }
        }
        str = str + pq.top().second;
        if(str.size()>s.size()){
            str.pop_back();
        }
        return str;
    }
};

// even = n/2;
// odd = n+1/2;
//         2-1
//         3-2
//         4-2
//         5-3
//         6-3
//         7-4
//         8-4