class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n = profits.size();
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
         priority_queue<int>pq;
        int i=0;
        while(k--){
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty())break;
           
            w+= pq.top();
            pq.pop();
            
        }
        // time complexity is ---(nlogn)
        return w;
    }
};