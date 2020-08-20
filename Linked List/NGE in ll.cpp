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
struct node{
  int idx;
    int data;
};
class Solution {
public:
    int getLength(ListNode* ptr)
    {
        int cnt=0;
        while(ptr)
        {
            ptr=ptr->next;
            cnt++;
        }
        return cnt;
    }
    vector<int> nextLargerNodes(ListNode* head) {
    stack<node>st;
        map<int,int>mp;
        int i=0;
        ListNode* ptr=head;
        node temp;
        while(ptr!=NULL)
        {
            if(st.empty()){
                temp.data=ptr->val;
                temp.idx=i;
                st.push(temp); i++; ptr=ptr->next; continue;
            }
            while(!st.empty() && st.top().data < ptr->val){
                mp[st.top().idx]=ptr->val;
                st.pop();
            }
            temp.data=ptr->val; temp.idx=i; i++; ptr=ptr->next;
            st.push(temp);
        }
        while(!st.empty())
        {
            mp[st.top().idx]=0;
            st.pop();
        }
        i=0;
        ptr=head;
        vector<int>ans;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            ans.push_back(mp[i]);
            i++;
        }
        return ans;
    }
};
