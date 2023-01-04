class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>ump;
        for(int i=0;i<tasks.size();i++){
            ump[tasks[i]]++;
        }
        int ans=0;
        for(auto it :ump){
            if(it.second==1)return -1;
            else if(it.second==2)ans+=1;
            else if(it.second%3==0)ans += (it.second)/3;
            else{
                ans += (it.second/3)+1;
            }
            
        }
        return ans;
    }
};