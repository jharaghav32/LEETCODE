/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>ump;
    int pos;
    Solution(ListNode* head) {
       ListNode*ptr= head;
        pos=0;
        while(ptr){
            ump[pos]=ptr->val;
            ptr = ptr->next;
            pos++;
        }
    }
    
    int getRandom() {
      int random = rand()%pos;
        return ump[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */