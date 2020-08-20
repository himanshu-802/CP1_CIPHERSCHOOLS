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
    ListNode* findLoop(ListNode* ptr)
    {
        ListNode* slow=ptr;
        ListNode* fast=ptr;
        while(1)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL || fast->next==NULL) return NULL;            
            if(slow==fast) return slow;
            
        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* ptr=findLoop(head);
        if(ptr==NULL)return ptr;
        ListNode* qtr=head;
        while(ptr!=qtr)
        {
            ptr=ptr->next;
            qtr=qtr->next;
        }
        return ptr;
        
    }
};
