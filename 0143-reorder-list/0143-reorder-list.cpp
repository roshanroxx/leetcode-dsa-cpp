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

    ListNode* reorder(ListNode* ohead)
    {
        ListNode* tail = ohead;
        if(ohead->next==NULL)
        {
            return ohead;
        }
        ListNode* nhead = ohead->next;
        
        while(tail->next->next != NULL)
        {
            tail = tail->next;
        }
        ohead->next = tail->next;
        tail->next = NULL;
        ListNode* temp = ohead->next;
        if(temp)
        temp->next = nhead;
        return ohead;
    }

    void reorderList(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL)
        {
            return; 
        }
        ListNode* ohead = head;
        while(ohead->next!=NULL && ohead->next->next!=NULL)
        {
            ohead = reorder(ohead);
            if(ohead->next==NULL)
            {
                break;
            }
            ohead = ohead->next->next;

        }

    }
};