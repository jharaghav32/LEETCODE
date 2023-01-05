class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt=0;
        sort(points.begin(),points.end());
        int end=INT_MAX;
        for(int i=0;i<points.size();i++){
            if(points[i][0]>end){
                cnt++;
                end = points[i][1];
            }
            else{
                end = min(end,points[i][1]);
            }
        }
        return cnt+1;
    }
};