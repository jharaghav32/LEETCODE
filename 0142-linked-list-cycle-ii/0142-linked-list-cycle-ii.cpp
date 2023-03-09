/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       
        ListNode*ptr = head;
        unordered_map<ListNode*,int>ump;
        while(ptr){
            if(ump.find(ptr)!=ump.end())return ptr;
            ump[ptr]++;
            ptr=ptr->next;
        }
        return NULL;
    }
};