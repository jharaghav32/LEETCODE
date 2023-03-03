class Solution {
public:
    int strStr(string haystack, string needle) {
     int h =haystack.length();
        int n = needle.length();
        bool flag=false;
        int index;
      for(int i=0;i<h;i++){
          for(int j=0;j<n;j++){
              if(haystack[i+j]==needle[j]){
                  flag=true;
              }
              else{
                  index=-1;
                  flag=false;
                  break;
              }
             
          }
           if(flag)
                  return i;
      }
        return index;
    }
};