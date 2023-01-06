class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<pair<int,int>>task;
        for(int i=0;i<tasks.size();i++){
            task.push_back({tasks[i][0],i});
        }
        sort(task.begin(),task.end());
        long long initProcess = task[0].first;
        int i=0;
        int n=tasks.size();
        vector<int>ans;
        while(i<n){
            if(task[i].first)
            while(i<n && task[i].first<=initProcess ){
                pq.push({tasks[task[i].second][1],task[i].second});
                i++;
            }
            if(!pq.empty()){
            auto tp = pq.top();
            ans.push_back(tp.second);
            initProcess+= tp.first;
            pq.pop();
            }
            else{
                initProcess=task[i].first;
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
            
    }
};