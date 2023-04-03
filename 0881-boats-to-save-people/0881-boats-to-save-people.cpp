class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        // we sort the vector and then use two pointer approach
        sort(people.begin(),people.end());
        int ans=0; 
       int left = 0;
        int right = n-1;
        // mark the left and right pointer
        while(left<=right){
            // if both left and right are under the limit that means we can easily take that element that is present at i and j into boat so take that element and increment the answer and move both pointer as we have taken that element
            if(people[left]+people[right]<=limit){
                left++;
                right--;
            }
            // if it exceeds the limit then that means we can't take both element we have to take only one element so take the element having max value and increment the answer  because we require min boat so take that one and decrement the right pointer as we now can't take that element again 
            else
                right--;
            ans++;
        }
        return ans;
       
    }
};