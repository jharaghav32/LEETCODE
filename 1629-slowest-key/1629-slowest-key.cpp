class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxtime=releaseTimes[0];
        char ansc= keysPressed[0];
        
        for(int i=1;i<releaseTimes.size();i++){
                if(maxtime<releaseTimes[i]-releaseTimes[i-1])
                {
                    ansc=keysPressed[i];
                    maxtime=releaseTimes[i]-releaseTimes[i-1];
                }
            else if(maxtime==releaseTimes[i]-releaseTimes[i-1]){
                ansc=max(ansc,keysPressed[i]);
            }
        }
        return ansc;
        
    }
};