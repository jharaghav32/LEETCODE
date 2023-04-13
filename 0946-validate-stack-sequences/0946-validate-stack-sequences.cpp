class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //first initialised the two pointer to zero of both array
        int i=0;
        int j=0;
        //As in first approach we created a stack to take care of which element can be removed but here we considered pushed array as a stack using pointer 
        //we traverse pushed array
        for(int k=0;k<pushed.size();k++){
            //push element into pushed array (as a stack)
            pushed[i]=pushed[k];
            //then increment i which specify whcih position now we can push next element
            i++;
            //after that check whether the last element of pushed array that is (i-1) is equal to popped element
            while(i>0 && pushed[i-1]==popped[j]){
                //remove elment using pointer  decrementing the i pointer means now we can push next elment on one less positoin and increment the j pointer to get next popped element
                i--;
                j++;
            }
        }
        // if i pointer reaches 0 it means we have succesfully popped out all element so return true
        if(i==0)return true;
        else return false;
    }
};