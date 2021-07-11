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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ans = head;
        if(head->next==NULL) return NULL;
        if(n==1){
            while(head->next->next!=NULL){
                head=head->next;
            }
            head->next = NULL;
        }
        else{
            while(n>1){
                fast = fast->next;
                n--;
            }
            while(fast->next!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
            // if(slow == ans){
            //     return ans;
            // }
                slow->val = slow->next->val;
                slow->next = slow->next->next;    
            }
        return ans;
    }
};