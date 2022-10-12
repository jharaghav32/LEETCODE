class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int a,b,c;
             a = pq.top();
            pq.pop();
             b = pq.top();
            pq.pop();
             c = pq.top();
            pq.pop();
        int ans=0 ;
        if(a>=(b+c))
            ans=0;
        else{
            ans=a+b+c;
            return ans;
        }
            
        while(!pq.empty()){
            a = b;
            b = c;
           if(pq.empty())
               return ans;
            else{
                c = pq.top();
                pq.pop();
                if(a<(b+c)){
                    int curperim = a+b+c;
                     return curperim;
                }
            }
        }
        return ans;
    }
};