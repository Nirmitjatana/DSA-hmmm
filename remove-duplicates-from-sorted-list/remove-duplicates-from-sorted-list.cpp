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
// class Solution {
// public:
//     void remove(ListNode*&temp,ListNode*&head){
//         temp->next=head->next;
//         delete(head);
//     }
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* temp;
//         ListNode* ret = head;
//         temp = head;
//         head = head->next;
//         while(head->next!=NULL){
//             if(head->val == temp->val){
//                 remove(temp,head);
//             }
//             temp = temp->next;
//             head = head->next;
//         }
//         return ret;
//     }
    
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** curr = &head;
        while(*curr && (*curr)->next){
            if((*curr)->val == (*curr)->next->val)
                *curr = (*curr)->next;
            else
                curr = &(*curr)->next;
        }
        return head;
    }
};