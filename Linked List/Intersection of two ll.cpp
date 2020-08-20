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
    int getCount(ListNode* ptr)
    {
        int cnt=0;
        while(ptr!=NULL){
            ptr=ptr->next; cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=getCount(headA);
        int c2= getCount(headB);
        if(c1<c2){
            c2=c2-c1;
            while(c2--)
            {
                headB=headB->next;
            }
            while(headA!=headB){
                headA=headA->next;
                headB=headB->next; 
            }
            return headA;
        }
        else{
            c1=c1-c2;
            while(c1--)
            {
                headA=headA->next;
            }
            while(headA!=headB){
                headA=headA->next;
                headB=headB->next; 
            }
            return headA;

            
        }
    }
};
