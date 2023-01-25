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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* small = new ListNode(-2);
        // ListNode* last = head;
        ListNode* smalll = small;
        // ListNode* last = head;
        // ListNode* large = new ListNode(-1);
        ListNode* large = NULL;
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        head = temp;
        bool k =false;

        while(head->next!=NULL){
            if(head->next->val < x){
                small->next = head->next;
                // if(head->next->next!=NULL){
                //     break;
                // }
                head->next = head->next->next;
                small = small->next;
                small->next = NULL;
            }
            else{
                if(k== false){
                    large = head->next;
                    k=true;
                }
                head = head->next;
            }
        }
        small->next = large;

        // while(last->next!=NULL &&  last->next->val<x)
        // {
        //     cout<<last->val<<"  ";
        //     last = last->next;
        // }
        // if(last->next==NULL)
        // {
        //     return head;
        // }
        // large = last->next;
        // small = last;
        // temp = last->next;
        // small->next =NULL;
        // cout<<small->val;
        // while(last->next!=NULL)
        // {
        //     if(last->next->val<x)
        //     {
        //         last = last->next;
        //         continue;
        //     }
        //     cout<<last->val;
        //     small->next = last->next;
        //     small = small->next;
        //     last->next = last->next->next;
        //     small->next =NULL;
            
        //     // large->next = last->next;
        //     // large = large->next;
        //     // last->next = large->next;
        //     continue;
        // }
        // if(last->next->val>x)
        // {
        //     large->next = last->next;
        //     large = large->next;
        // }
        // last->next = small;
        return smalll->next;
    }
};