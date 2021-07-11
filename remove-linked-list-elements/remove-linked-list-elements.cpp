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
//     void removeNode(ListNode* head){
//         head->val = head->next->val;
//         head->next = head->next->next;
//     }
//     // ListNode* removeHead(ListNode* head){
//     //     ListNode* temp = head->next;
//     //     delete(head);
//     //     head = temp;
//     //     cout << "in";
//     //     return head;
//     // }
//     ListNode* removeElements(ListNode* head, int val) {
//         if(head == NULL){
//             return head;
//         }
//         ListNode* ret = head;
//         while(ret->val==val){
//             ret=ret->next;
//         }
//         head = ret;
//         // ListNode* start = head;
//         // while(ret->val==val){
//         //     ret = removeHead(head);
//         //     // start = start->next;
//         // }
//         // ListNode* ans = head;
//         while(head->next!=NULL){
//             head = head->next;
//             if(head->val == val){
//                 cout << "in";
//                 removeNode(head);
//             }
//         }
//         if(head->val == val){
//             // removeTail(head);
//         }
//         return head;
//     }
// };




class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode* he=head;
       while(he!=NULL and he->val==val)
       {
           he=he->next;
       }
        if(he==NULL)
            return NULL;
        head=he;
    while(he->next!=NULL)
    {
        if(he->next->val==val)
        {
            he->next=he->next->next;
            continue;
        }
        he=he->next;
    }
    
       
        return head;
    }
};
