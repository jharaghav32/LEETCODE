class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int i1=0;
        int i2=0;
        int i3=0;
        for(int i=n-1;i>=0;i--){
            int ans = INT_MIN;
            ans=max(ans,stoneValue[i]-i1);
            if(i+1<n)
                ans=max(ans,stoneValue[i]+stoneValue[i+1]-i2);
            if(i+2<n)
                ans=max(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-i3);
              
             i3=i2;
             i2=i1;
             i1 = ans;
        }
        if(i1>0)return "Alice";
        else if(i1<0)return "Bob";
        return "Tie";
    }
};