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
    ListNode* midPoint(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
    void print(ListNode* root)
    {
        //cout<<root->val<<endl;
        while(root!=NULL)
        {
          //  cout<<"YESSS";
            cout<<root->val<<" ";
            root=root->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode* ptr=head;
        int cnt=0;
        while(ptr!=NULL)
        {
            cnt++;
            ptr=ptr->next;
        }
        ptr=midPoint(head);
        if(cnt%2==1)ptr=ptr->next;
        ListNode* curr=ptr;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ptr=prev;
       // print(ptr);
        while(ptr!=NULL)
        {
            if(head->val!=ptr->val){
                return false;
            }
            head=head->next;
            ptr=ptr->next;
        }
        return true;
       
    }
};
