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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev =new ListNode(-1);
        ListNode* top = prev;
        int count =0;
        while(head!=NULL){
            count=0;
            while(head->next!=NULL && head->val==head->next->val){
                count++;
                head =head->next;
            }
            if(count==0){
                prev->next = head;
                prev = prev->next;
                head=head->next;
                prev->next =NULL;
            }
            else{
                head = head->next;
            }
        }

        return top->next;

    }
};