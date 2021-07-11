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
// public:
//     int getDecimalValue(ListNode* head) {
//         int i=0,ans=0;
//         ListNode* p = head;
//         while(p!=NULL){
//             i++;
//             p=p->next;
//         }
//         p=head;
//         while(p!=NULL && i>=0){
//             ans+=pow(2,i-1)*p->val;
//             p=p->next;
//             i--;
//         }
//         return ans;
//     }
    
    
    public:
    int getDecimalValue(ListNode* head) {
        int num=0;
        int i=0;
        
        while(head!=NULL){
            num=2*num + head->val ; 
            head= head->next;
            i++;
        }
        
        return num;
    }
};


