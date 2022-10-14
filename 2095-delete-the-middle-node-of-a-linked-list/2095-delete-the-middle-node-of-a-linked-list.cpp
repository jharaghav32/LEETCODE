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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* nextnode;
        ListNode* curr = head;
        int cnt=1;
        while(curr->next){  
            curr=curr->next;
            cnt++;
        }
        if(cnt==1)return NULL;
        cnt = cnt/2;
        curr=head;
        while(cnt){
            nextnode = curr->next;
            prev=curr;
            curr=nextnode;
            cnt--;
        }
        nextnode=curr->next;
        prev->next=nextnode;
        return head;
        
    }
};