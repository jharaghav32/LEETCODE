class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n==2)return (stones[1]-stones[0]);
       
        int ans = max(stones[1]-stones[0],stones[2]-stones[0]);
        int i = 1;
        while(i<n-1){
            if(i<=n-3)
            ans  = max(ans,stones[i+2]-stones[i]);
            else
                ans = max(ans,stones[i+1]-stones[i]);
            i+=2;
        }
        i=2;
          while(i<n-1){
              if(i<=n-3)
            ans  = max(ans,stones[i+2]-stones[i]);
              else 
                  ans=max(ans,stones[i+1]-stones[i]);
            i+=2;
        }
        return ans;
    }
};