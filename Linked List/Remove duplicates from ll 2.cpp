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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;
        temp->next=head;
        ListNode* ptr=head;
        ListNode* qtr=head;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            if(ptr->next->val==ptr->val){
                while( qtr!=NULL && qtr->val==ptr->val )
                {
                    qtr=qtr->next;
                }
                temp->next=qtr;
                ptr=qtr;
                
            }
            else{
                temp=ptr;
                ptr=ptr->next;
                qtr=qtr->next;
            }
        }
        return dummy->next;
        
    }
};
