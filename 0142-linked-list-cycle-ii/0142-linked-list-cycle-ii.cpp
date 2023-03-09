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
       if(!head || !head->next){
           // cout<<"checking1"<<" ";
           return NULL;
       }
        ListNode*slow = head->next;
        ListNode*fast=head->next->next;
        
        while(slow!=fast && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
       if(slow!=fast){
           // cout<<"checking"<<" ";
           return NULL;
       }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};