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
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         int pos = 1;
//         ListNode* ret = head;
//         ListNode* P;
//         ListNode* lb;
//         while(pos<=left){
//             pos++;
//             P = head;
//             head = head->next;
//         }
        
        
//         ListNode* C = head;
//         // p = 2
//         // c = 3
//         ListNode* N;
//         while(pos<right){
//             N = C->next;

            
//             C->next = P;
//             P = C;
//             C = N;
 
//             pos++;
//         }
//         head ->next = C;
//         C -> next = N;
//         // head = P;
//         return ret;
//     }
// };

class Solution {
    public:
ListNode *reverse(ListNode *head,ListNode *end){
        ListNode *curr=head,*prev=end,L,*n;
        while(curr->next!=end){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        curr->next=prev;
        return curr;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(left==right){
            return head;
        }
        ListNode *p=head,*q=head;
        int i=2;
        while(i<left){
            p=p->next;
            i++;
        }
        i=1;
        while(i<right){
            i++;
            q=q->next;
        }
        if(left!=1 && right>1){
            p->next=reverse(p->next,q->next);
        }else{
            return reverse(p,q->next);
        }
        
        return head;
    }
};