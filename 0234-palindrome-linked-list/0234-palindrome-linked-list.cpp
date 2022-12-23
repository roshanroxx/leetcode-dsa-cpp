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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
        {
            return true;
        }
        ListNode* end = head;
        ListNode* slow = head;
        while(end->next !=NULL && end->next->next!=NULL)
        {
            slow = slow->next;
            end = end->next->next;
        }
        end = slow;
        slow = slow->next;
        end->next=NULL;
        ListNode* temp = NULL;
        while(slow!=NULL)
        {
            end = slow;
            slow = slow->next;
            end->next = temp;
            temp = end;
        }
        while(end!=NULL)
        {
            if(end->val!=head->val)
            {
                return false;
            }
            end = end->next;
            head = head->next;
        }
        return true;
    }
};