class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<pair<int,int>>task;
        for(int i=0;i<tasks.size();i++){
            task.push_back({tasks[i][0],i}); // store the starting time and index
        }
        sort(task.begin(),task.end());// sort that so that we get least time first
        long long initProcess = task[0].first;// initialise the starting time 
        int i=0;
        int n=tasks.size();
        vector<int>ans;
        while(i<n){
            while(i<n && task[i].first<=initProcess ){// check if any starting time is less than or equal to the time at which cpu is 
                pq.push({tasks[task[i].second][1],task[i].second}); //push proces time and inex in min heap
                i++;// increment i to check next element
            }
            if(!pq.empty()){// if element is present in minheap remove those having less processing time and insert its index in answer vector 
            auto tp = pq.top();
            ans.push_back(tp.second);
            initProcess+= tp.first;
            pq.pop();
            }
            else{
                // if minheap is empty it means there is no element whcih is available at current cpu time so move the time to next element available time and then repeat the process untill we covered all tasks
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