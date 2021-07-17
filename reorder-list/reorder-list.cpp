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
    bool stop = false;
    void add(ListNode** head, ListNode* tail){
        if(tail == NULL) return;
        add(head, tail->next);
        if(stop) return;
        if((*head) == tail || (*head)->next == tail){
            tail->next = NULL;
            stop = true;
            return;
        }
        ListNode* n = (*head) -> next;
        (*head) -> next = tail;
        tail->next = n;
        (*head) = n;
    }
    void reorderList(ListNode* head) {
        ListNode* tail = head;
        int counter = 0;
        add(&head, tail);
    }
};


// class Solution {
// public:
//     void util(ListNode** h,ListNode* tmp,bool& done){
//         if(tmp == NULL)
//             return;
        
//         util(h,tmp->next,done);
//         if(done) return;
//         if(*h == tmp || (*h)->next == tmp){
//             tmp->next = NULL;
//             done = true;
//             return;
//         }
//         ListNode* n = (*h)->next;
//         (*h)->next = tmp;
//         tmp->next = n;
//         (*h) = n;
//     }
    
//     void reorderList(ListNode* head) {
//         if(head == NULL || head->next == NULL || head->next->next == NULL)
//             return;
//         ListNode* h = head;
//         ListNode* tmp = head;
//         bool done = false;
//         util(&h,tmp,done);
//     }
// };