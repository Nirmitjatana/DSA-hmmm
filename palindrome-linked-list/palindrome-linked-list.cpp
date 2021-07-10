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
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next==NULL) return true;
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         vector<int> ch;
//         while(fast && fast->next!= NULL){
//             ch.push_back(slow->val);
//             slow = slow->next;
//             fast = fast->next->next;
//             // cout << "in";
//         }
//         slow = slow->next;
//         ch.push_back(slow->val);
//         int len = ch.size(); //2
//         cout << len;
//         int i = 1;
//         while(slow->next!=NULL){
//             slow = slow->next;
//             cout << slow->val;
//             // cout << ch[len-i];
//             // if(slow->val!=ch[len-i]){
//             //     return false;
//             // }
//             i++;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();

        for(int i=0;i<n;i++){
            if(v[i]!=v[n-i-1]){
                return false;
            }
        }
        return true;
    }
};