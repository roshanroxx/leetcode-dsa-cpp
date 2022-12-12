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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0, carry=0,d;
        ListNode* l3= new ListNode(0);
        ListNode* l4 = l3;
        while(l1!=NULL && l2!=NULL)
        {
            sum = l1->val+l2->val+carry;
            d = sum/10;
            sum = sum%10;
            l3->next = new ListNode(sum);
            carry = d;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2 ==  NULL && l1!=NULL)
        {
            while(l1!=NULL)
            {
                sum = l1->val+carry;
                d= sum/10;
                sum = sum%10;
                l3->next = new ListNode(sum);
                carry = d;
                l3 = l3->next;
                l1 = l1->next; 
            }
        }
        else if(l1 ==  NULL && l2!=NULL)
        {
            while(l2!=NULL)
            {
                sum = l2->val+carry;
                d= sum/10;
                sum = sum%10;
                l3->next = new ListNode(sum);
                carry = d;
                l3 = l3->next;
                l2 = l2->next; 
            }
        }
        if(carry>0)
        {
            l3->next = new ListNode(carry);
        }
        return l4->next;
    }
};