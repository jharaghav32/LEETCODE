class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        unordered_map<int,int>ump;
        for(int i=0;i<pushed.size();i++){
            ump[pushed[i]]=i;
        }
        int mark;
        int push=-1;
        for(int i=0;i<popped.size();i++){
            int elemIdx = ump[popped[i]];
            mark = push+1;
            while(mark<=elemIdx){
                st.push(mark); 
                push = mark;
                mark++;
            }
           if(st.top()==elemIdx){
               st.pop();
           }
            else{
                return false;
            }
            
        }
        return true;
    }
};