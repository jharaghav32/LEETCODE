class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        char prev=chars[0];
        int i=1;
        int cnt=1;
        for(int j=1;j<n;j++){
            if(prev==chars[j])
                cnt++;
            else{
                if(cnt>=2 && cnt<=9){
                    chars[i]= (char)('0'+cnt);
                    i++;
                   
                }
                else if(cnt>=10){
                    vector<char>v;
                    while(cnt>0){
                        char rem = (char)((cnt%10)+'0');
                        v.push_back(rem);
                         cnt = cnt/10;
                    }
                    for(int j=v.size()-1;j>=0;j--){
                        if(i==0)i++;
                        chars[i]=v[j];
                        i++;
                    }
                }
                cnt=1;
                prev=chars[j];
                chars[i]=prev;
                i++;
            
        }
        }
         if(cnt>=2 && cnt<=9){
                   chars[i]= (char)('0'+cnt);
                  i++;
                }
                else if(cnt>=10){
                   
                    vector<char>v;
                    while(cnt>0){
                        char rem = (char)((cnt%10)+'0');
                        v.push_back(rem);
                         cnt = cnt/10;
                    }
                    for(int j=v.size()-1;j>=0;j--){
                        
                        chars[i]=v[j];
                        i++;
                    }
                  
                    cnt=0;
                }
     
        return i;
        
    }
};