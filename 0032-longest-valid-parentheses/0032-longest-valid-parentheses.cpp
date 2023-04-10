class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<bool>val(n,false);
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){    
         if(s[i]=='(')
            st.push({s[i],i});
            else if(s[i]==')' && !st.empty() && st.top().first=='(')
            {
               val[i]=true;
                val[st.top().second]=true;
                st.pop();
            }
          else{
              while(!st.empty()){
                  val[st.top().second]=false;
                  st.pop();
              }
          }
        }
       while(!st.empty()){
            val[st.top().second]=false;
                  st.pop();
       }
        int ans=0;
        int tempans=0;
       for(int i=0;i<n;i++){
           if(val[i]==true){
               tempans++;
           }
           else{
               ans = max(ans,tempans);
               tempans=0;
           }
       }
        ans=max(ans,tempans);
        return ans;
    }
};