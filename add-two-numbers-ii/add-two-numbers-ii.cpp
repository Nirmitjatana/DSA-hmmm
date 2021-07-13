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
    void insertHead(ListNode* &l3,int data){
        if(l3 == NULL){
            l3 = new ListNode(data);
            return;      
        }
        else{
            ListNode* in = new ListNode(data);
            in->next = l3;
            l3 = in;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        int carry = 0;
        ListNode* l3 = NULL;
        // stack 1 push 
        while(l1->next!=NULL){
            num1.push(l1->val);
            l1 = l1->next;
        }
        num1.push(l1->val);
        // stack 2 push
        while(l2->next!=NULL){
            num2.push(l2->val);
            l2 = l2->next;
        }
        num2.push(l2->val);
        
        while(!num1.empty() and !num2.empty()){
            if(num1.top()+num2.top()+carry > 9){
                insertHead(l3,(num1.top()+num2.top()+carry)%10);    
                carry = 1;
            }
            else{
                insertHead(l3,num1.top()+num2.top()+carry);
                carry = 0;
            }
            num1.pop();
            num2.pop();
        }
        
        while(!num1.empty() and num2.empty()){
            if(num1.top()+carry > 9){
                insertHead(l3,(num1.top()+carry)%10);    
                carry = 1;
            }
            else{
                insertHead(l3,num1.top()+carry);
                carry = 0;
            }
            // insertHead(l3,num1.top()+carry);
            num1.pop();
        }
        
        while(num1.empty() and !num2.empty()){
            if(num2.top()+carry > 9){
                insertHead(l3,(num2.top()+carry)%10);    
                carry = 1;
            }
            else{
                insertHead(l3,num2.top()+carry);
                carry = 0;
            }
            // insertHead(l3,num2.top()+carry);
            num2.pop();
        }
        if(carry!=0){
            insertHead(l3,1);
        }
        return l3;
    }
};