//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>newv=nums;
	    unordered_map<int,int>ump;
	    int n = nums.size();
	    for(int i=0;i<n;i++){
	        ump[nums[i]]=i;
	    }
	    sort(nums.begin(),nums.end());
	    int ans=0;
	    for(int i=0;i<n;i++){
	        if(nums[i]!=newv[i]){
	            int idx = ump[nums[i]];
	            ump[newv[i]]=idx;
	            ump[newv[idx]]=i;
	            swap(newv[i],newv[idx]);
	            ans++;
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends