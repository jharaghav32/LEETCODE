class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ump;
        for(int i=0;i<nums2.size();i++){
            ump[nums2[i]]++;
        }
        vector<vector<int>>ans(2);
        for(int i=0;i<nums1.size();i++){
            if(ump[nums1[i]]==0){
                ans[0].push_back(nums1[i]);
                ump[nums1[i]]++;
            }
        }
          unordered_map<int,int>ump1;
        for(int i=0;i<nums1.size();i++){
            ump1[nums1[i]]++;
        }
         for(int i=0;i<nums2.size();i++){
            if(ump1[nums2[i]]==0){
                ans[1].push_back(nums2[i]);
                 ump1[nums2[i]]++;
            }
        }
        return ans;
        
    }
};