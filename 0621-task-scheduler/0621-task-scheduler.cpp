class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>ump;
        for(int i=0;i<tasks.size();i++){
            ump[tasks[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it :ump){
            pq.push({it.second,it.first});
        }
        vector<int>cp(27,0);
        auto it = pq.top();
        pq.pop();
        int gap = (it.first-1)*n;
        int cnt = it.first;
        int ans = gap+it.first;
        while(!pq.empty()){
          
           auto it = pq.top();
            pq.pop();
          
            if(cnt>it.first && gap>=it.first){
                gap = gap-it.first;
            }
            else if(cnt==it.first && gap>=it.first){
                gap = gap-(it.first-1);
                ans+=1;
            }
            else{
               ans += it.first-gap;
                gap=0;
            }
        }
        return ans;
    }
};