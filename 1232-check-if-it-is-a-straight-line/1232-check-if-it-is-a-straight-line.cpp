class Solution {
public:
    int INF=1e5+1;
    bool checkStraightLine(vector<vector<int>>& cods) {
        int x = cods[0][0];
        int y = cods[0][1];
         double m ;
        for(int i=1;i<cods.size();i++){
            int currx  = cods[i][0];
            int curry = cods[i][1];
            if(i==1){
              int xdiff =(x-currx);
              int ydiff = (y-curry);
                if(xdiff==0){
                    m = INF;
                }
                else{
                    m = (double)ydiff/xdiff;
                }
            }
            else{
              int xdiff = (x-currx);
              int ydiff = (y-curry);
                double currm;
                if(xdiff==0){
                    currm = INF;
                }
                else{
                    currm = (double)ydiff/xdiff;
                }
                if(m!=currm)return false;
            }
            
        }
        return true;
    }
};