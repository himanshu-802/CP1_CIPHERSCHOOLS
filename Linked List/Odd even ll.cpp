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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* ptr=head;
        ListNode* qtr=head->next;
        ListNode* rtr=qtr;
        while(1)
        {
            cout<<ptr->val<<" "<<qtr->val<<endl;
            if(ptr->next!=NULL && ptr->next->next!=NULL)
            {
                ptr->next=qtr->next;
                ptr=ptr->next;
            }
            
            if(ptr->next==NULL){
                qtr->next=NULL;
                break;
            }
            if(ptr->next->next==NULL)
            {
                qtr->next=ptr->next;
                qtr=qtr->next;
                qtr->next=NULL;
                break;
            }
            if(qtr->next!=NULL && qtr->next->next!=NULL)
            {
                qtr->next=ptr->next;
                qtr=qtr->next;
            }
            
        }
        ptr->next=rtr;
        return head;
        
        
    }
};
