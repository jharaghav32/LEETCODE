class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
    int n = nums.size();
        int mini=INT_MAX;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0)nums[i]=nums[i]*2;
            pq.push(nums[i]);
            mini=min(mini,nums[i]);
        }
        int dev=INT_MAX;
        while(pq.top()%2==0){
            int maxi=pq.top();
            dev=min(dev,(maxi-mini));
            pq.pop();
            maxi=maxi/2;
            pq.push(maxi);
            mini=min(mini,maxi);
        }
        dev=min(dev,(pq.top()-mini));
        return dev;
    }
};