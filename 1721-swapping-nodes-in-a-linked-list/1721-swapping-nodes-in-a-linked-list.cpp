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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* fast = head;
        int count=0;
        while(fast!=NULL)
        {
            count++;
            fast = fast->next;
        }
        if(k>count/2)
        {
           k = count-k+1; 
        }
        fast = head;
        int l=1;
        while(l!=k)
        {
            fast = fast->next;
            l++;
        }
        int m = fast->val;
        l=k;
        while(l!=count-k+1)
        {
            fast = fast->next;
            l++;
        }
        int n = fast->val;
        fast->val =m;
        l=1;
        fast = head;
        while(l!=k)
        {
            fast = fast->next;
            l++;
        }
        fast->val = n;
        return head;
    }
};