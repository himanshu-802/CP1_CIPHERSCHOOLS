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
    
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* dummy=new ListNode(0), *tail=dummy;
        tail->next=head;
        while(head && head->next){
            ListNode* nextPtr=(head->next)->next;
            tail->next= head->next;
            (head->next)->next=head;
            tail=head;
            tail->next=nextPtr;
            head=nextPtr;
        }
        head=dummy->next;
        return head;
    }
};
