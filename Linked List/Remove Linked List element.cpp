/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
//  */
// if(head==nullptr) return head;
//         while(head!=nullptr && head->val==val){
//             head = head->next;
//         }
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
//         while(curr!=nullptr){
//             if(curr->val==val){
//                 prev->next = curr->next;
//                 curr = curr->next;
//             }
//             else{
//                 prev = curr;
//                 curr = curr->next;        
//             }
//         }
//         return head;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* dummy=new ListNode(0);
        
        ListNode* ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->val==val)
            {
                dummy->next=ptr->next;
                ptr=ptr->next;
            }
            else{
             dummy=ptr;
             ptr=ptr->next;
            }
        //    ptr=ptr->next;
        }
        return head;
        
    }
};
