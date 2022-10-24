class Solution {
public:
    void subseq(vector<string>&arr,int idx,int currlen,vector<int>vis,int &ans){
        if(idx>=arr.size()){
            ans = max(ans,currlen);
            return;
        }
        vector<int>t=vis;// initialse a new string with visited string
        bool flag=1;// it will mark wether we can take the string at index idx or not if flag is 1 it means we have taken and if it is zero it means we  are not able to take
        //we will traverse the string at index idx
        for(int i=0;i<arr[idx].size();i++){
            char c = arr[idx][i];
            if(t[c-'a']==1)// and check whether this character is present or not if it is present then break out from loop and don't take this string 
            {
                flag=0;
                break;
            }
            t[c-'a']=1;
        }
        if(flag==1)// it means any character of stirng is not present earlier in vis array
        subseq(arr,idx+1,currlen+arr[idx].size(),t,ans);//here we take the string our lenght increase by its size and we update our vis array with t which is now updated array
        subseq(arr,idx+1,currlen,vis,ans);// here we don't take the string so no need to send t send the earllier vis array and increase the index.
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        vector<int>vis(26,0);// ye actually check krega ki kons character hamara string me exist krta hai 
        subseq(arr,0,0,vis,ans);
        return ans;
    }
};