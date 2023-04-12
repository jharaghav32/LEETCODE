class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
      
        string can = "";
        stack<string> st;
       for(int i=0;i<n;i++){
           // whenever / occurs check can string whcih is the string between two slash
           // if it is '..' that means we have to move one directy up so remove the file from stack otherwise if can is not empty and it is not equal to singl '.' that means a directory exist between slash so push it into stack and reinitilaise it to empty string
           if(path[i]=='/'){
               if(can == ".."){
                   if(!st.empty())st.pop();
               }
                   else if(can!="." && can!="")
                       st.push(can);
                   can="";
               
           }
           else{
               can+= path[i];
           }
       }
        if(can==".."){
            if(!st.empty())st.pop();
            can="";
        }
        else{
            if(can!="." && can!="")
                st.push(can);
            can="";
        }
    
        if(st.empty())
            return "/";
        // after traversing remove the directory and append it after / 
        
        while(!st.empty()){
           if(st.top()!="/"){
               can = st.top()+can;
               st.pop();
               st.push("/");
           }
            else{
                can = st.top()+can;
                st.pop();
            }
        }
        
        return can;
        //time complexity --O(n) && Space complexity-O(n)
    }
};