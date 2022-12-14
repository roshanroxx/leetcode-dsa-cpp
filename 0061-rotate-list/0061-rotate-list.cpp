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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL)
        {
            return head;
        }
        if(head->next->next==NULL)
        {
            if(k%2==0)
            {return head;}
            else{
                head->next->next = head;
                head = head->next;
                head->next->next = NULL;
                return head;
            }
        }
        int count =1;
        ListNode* fast = head;
        while(fast->next!=NULL)
        {
            count=count+1;
            fast = fast->next;
        }
        k= k%count;
        if(k==0)
        {
            return head;
        }
        count = 1;

        fast = head;
        ListNode* slow = head;
        while(count!=k)
        {
            if(k==1)
            {
                break;
            }
            fast = fast->next;
            count = count+1;
        }
        while(fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* last = fast->next;
        fast = slow->next;
        slow->next = NULL;
        last->next = head;

        cout<<count<<endl;
        return fast;
    }
};