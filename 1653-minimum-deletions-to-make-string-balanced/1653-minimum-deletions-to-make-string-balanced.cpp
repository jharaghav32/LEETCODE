class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    ans++;
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
            
        }
        return ans;
    }
};