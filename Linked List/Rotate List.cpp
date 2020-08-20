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
    int getLength(ListNode* &ptr)
    {
        int cnt=0;
        ListNode* ptr1=ptr;
        while(ptr1){
            if(ptr1->next==NULL)ptr=ptr1;
            ptr1=ptr1->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int n=getLength(head);
        k= k%n;
        if(k==0){
            return head;
        }
        int kth= n-k;
        
        ListNode* dummy=new ListNode(0);
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(kth--)
        {
             prev=curr;
            curr=curr->next;
           
        }
        prev->next=NULL;
      
        head=curr;
        return head;
    }
};
