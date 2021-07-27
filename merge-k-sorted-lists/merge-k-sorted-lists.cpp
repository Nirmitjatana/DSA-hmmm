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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int small = INT_MAX;
        int pos=-1;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL) continue;
            if(lists[i]->val<small){
                small = lists[i]->val;
                pos = i;
                
            }
        }
        ListNode* l3;
        if(pos==-1){
            return NULL;            
        }
        
        cout << pos;
        l3 = lists[pos];
        lists[pos] = lists[pos]->next;
        l3 -> next = mergeKLists(lists);

        return l3;
    }
};