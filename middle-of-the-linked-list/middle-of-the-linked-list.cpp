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
    int len(ListNode* head){
        int length = 0;
        while(head->next!=NULL){
            length++;
            head= head->next;
        }
        return length+1;
    }
    ListNode* middleNode(ListNode* head) {
        int length = len(head);
        if(length % 2 == 0){
            length = length/2 + 1;
            while(length!=1){
            // cout << head->val;
            head=head->next; 
            length--;
        }
        }
        else{
            length = length/2;
            while(length!=0){
                cout << head->val;
                head=head->next; 
                length--;
        }
            
        }
        
        return head;
    }
};