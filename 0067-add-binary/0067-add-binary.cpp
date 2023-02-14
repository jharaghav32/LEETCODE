class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen  = b.size();
        string ans;
        int carry=0;
         while(alen>=0 && blen>=0){
             int sum = a[alen]-'0'+b[blen]-'0'+carry;
             if(sum ==3){
                 ans.push_back('1');
                 carry = 1;
             }
             else if (sum ==2){
                 ans.push_back('0');
                 carry =1;
             }
             else if(sum==1){
                 ans.push_back('1');
                 carry=0;
             }
             else{
                 ans.push_back('0');
                 carry=0;
             }
             alen--;
             blen--;
                 
         }
        while(alen>=0){
            int sum = a[alen]-'0'+carry;
            if(sum==2){
                ans.push_back('0');
                carry=1;
            }
            else if(sum==1){
                ans.push_back('1');
                 carry=0;
            }
            else{
                ans.push_back('0');
                 carry=0;
            }
            alen--;
        }
        while(blen>=0){
            int sum = b[blen]-'0'+carry;
            if(sum==2){
                ans.push_back('0');
                carry=1;
            }
            else if(sum==1){
                ans.push_back('1');
                 carry=0;
            }
            else{
                ans.push_back('0');
                 carry=0;
            }
            blen--;
        }
       
        if(carry!=0)
            ans.push_back('1');
                

        reverse(ans.begin(),ans.end());
        ans.pop_back();
        return ans;
    }
};