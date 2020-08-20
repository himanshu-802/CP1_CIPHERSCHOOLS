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
    ListNode* sortList(ListNode* head) {
     if(head==NULL || head->next==NULL)return head;
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l = sortList(slow->next);
        slow->next=NULL;
        ListNode* r= sortList(head);
        return merge(l,r);
    }
    
    ListNode* merge(ListNode* l, ListNode* r)
    {
        ListNode* dummy= new ListNode(0);
        ListNode* node= dummy;
        
        while(l && r)
        {
            if(l->val < r->val){
                node->next=l;
                l= l->next;
            }
            else {
                node->next=r;
                r=r->next;
            }   
            node=node->next;
        }
     
        if(l)node->next=l;
        else node->next=r;
        
        return dummy->next;
    }
};

