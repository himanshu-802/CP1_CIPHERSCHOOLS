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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val>=l2->val){
                dummy->next=l2;
                dummy=l2;
                l2=l2->next;
            }
            else {
                dummy->next=l1;
                dummy=l1;
                l1=l1->next;
            }
        }
        while(l1!=NULL)
        {
            dummy->next=l1;
            dummy=l1;
            l1=l1->next;;
        }
        while(l2!=NULL){
            dummy->next=l2;
            dummy=l2;
            l2=l2->next;
        }
        cout<<temp->val<<endl;
        return temp->next;
    }
};
