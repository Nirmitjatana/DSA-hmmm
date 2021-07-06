
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry=0;
//         ListNode* head = l1;
//         while( l1->next!= NULL || l2->next!=NULL ){
//             int sum = l1->val+l2->val+carry;
//             if(carry) carry=0;
//             if(sum >= 10){
//                 sum = sum%10;
//                 carry=1;
//             }
//             l1->val = sum;
//             // cout << l1->val;
//             // carry=0;
//             l1=l1->next;
//             l2=l2->next;
//         }
        
        
        
        
//         return head;
//     }
// };



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* temp = ans;
        
        int carry = 0;
        
        // Traversing the Linked Lists (l1 and l2) till one of them reaches null pointer
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            
            int v = sum%10;
            carry = sum/10;
            
            if(ans == NULL){
                ans = new ListNode(v);
                temp = ans;
            }
            else{
                ListNode* t = new ListNode(v);                
                temp->next = t;
                temp = temp->next;
            }
            
        }
        
        // Traversing the remaining Linked List l1
        while(l1 != NULL){
            int sum = l1->val + carry;
            l1 = l1->next;
            
            int v = sum%10;
            carry = sum/10;
            
            if(ans == NULL){
                ans = new ListNode(v);
                temp = ans;
            }
            else{
                ListNode* t = new ListNode(v);                
                temp->next = t;
                temp = temp->next;
            }
            
        }
        
        // Traversing the remaining Linked List l2        
        while(l2 != NULL){
            int sum = l2->val + carry;
            l2 = l2->next;
            
            int v = sum%10;
            carry = sum/10;
            
            if(ans == NULL){
                ans = new ListNode(v);
                temp = ans;
            }
            else{
                ListNode* t = new ListNode(v);                
                temp->next = t;
                temp = temp->next;
            }
            
        }
        
        // Checking if there is any carry-over to be added to the Linked List
        if(carry>0){            
            if(ans == NULL){
                ans = new ListNode(carry);
                temp = ans;
            }
            else{
                ListNode* t = new ListNode(carry);                
                temp->next = t;
                temp = temp->next;
            }
        }
        
        
        return ans;
    }
};