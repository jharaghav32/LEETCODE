class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()!=1 && pq.size()!=0){
            int x = pq.top();
            pq.pop();
            int y= pq.top();
            pq.pop();
            if(x!=y){
                pq.push(x-y);
            }
        }
        if(pq.size())return pq.top();
        return 0;
    }
};