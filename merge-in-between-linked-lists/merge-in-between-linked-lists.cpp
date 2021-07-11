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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* parent = list1;
        ListNode* branch = list1;
        ListNode* ans = list1;
        int count = 0;
        while(count<a-1){
            parent = parent->next;
            count++;
        }
        branch = parent;
        parent = branch->next;
        branch->next = list2;
        while(a<b){
            parent = parent->next;
            a++;
        }
        while(branch->next!=NULL){
            branch = branch->next;
        }
        branch->next = parent->next;
        return ans;
    }
};