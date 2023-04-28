class Solution {
    
    // if string is similiar then there exist only two different element at same index so we have to check at every index whether elements present at that index is equal or not if it is not equal increment the count and if count becomes greater than 2 that means it is not similiar as we cna't make them equal by just swapping two elements . Apart from that we return true if count == 2 or count==0 means equal string which is also similiar string as given 
    bool isSimilar(string s1, string s2) {
        int count = 0;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                count++;
                if(count > 2) {
                    return false;
                }
            }
        }
        return count == 2 || count == 0;
    }
    //our approach is just like in graph a nodes is connected to all other component here we consider that all strings are connected to each other and to traverse graph we use dfs and just like no of islands problem  here we call dfs for a single string and visit all the string that is similiar to that string so actually no of groups is no of dfs call (as we have done in various graph problems like visited the same node value )
public:
    int numSimilarGroups(vector<string>& A) {
        int result = 0;
        if(A.empty()) {
            return 0;
        }
        unordered_set<string> visited;
        for(string s : A) {
            if(!visited.count(s)) {
                dfs(s, A, visited);
                result++;
            }
        }
        return result;
    }
    
    void dfs(string curr, vector<string>& A, unordered_set<string>& visited) {
        if(visited.count(curr)) {
            return;
        }
        visited.insert(curr);
        for(int i = 0; i < A.size(); i++) {
            if(isSimilar(curr, A[i])) {
                dfs(A[i], A, visited);
            }
        }
    }
};