class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int minend = INT_MIN;
        int ovrlap=1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=minend){// menas a new room 
                cnt += ovrlap-1;
                ovrlap=1;
                minend=intervals[i][1];
            }
            else{
                ovrlap++;
                minend=min(minend,intervals[i][1]);
            }
        }
        return cnt+ovrlap-1;
    }
};