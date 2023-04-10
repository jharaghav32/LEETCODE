class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int>st;
     int n = s.size();
        //initially put -1 to show that until now the index of invalid parenthesis doesn't known to us so insert -1;
        st.push(-1);
        int ans=0;
        for(int i=0;i<n;i++){
            //if char is open bracket simply insert the index into stack
            if(s[i]=='('){
                st.push(i);
            }
            // if bracket is closed then remove the top element because that one matches the open bracket if matches bracket doesn't found that means stack becomes empty  so insert the index of closed bracket into stack that gives us a find that upto that index invalid parenthesis occurs that helps us to find the length
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                // on removal if stack is not empty  than we can calculated the length that is i- stack top elemetn because the after the top element the parenthesis is valid and we calculate its length
                ans = max(ans,(i-st.top()));
            }
        }
        return ans;
    }
    // timecomplexity -O(n) && Space--O(n)
};