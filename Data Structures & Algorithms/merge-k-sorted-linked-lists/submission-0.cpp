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
        int n = lists.size();        
        if(n == 0) return {};

        vector<int> value;

        for(auto it: lists){
            ListNode* temp = it;
            if(temp == NULL) continue;
            else{
                while(temp != NULL){
                    value.push_back(temp->val);
                    temp = temp->next;
                }
            }
        }

        sort(value.begin(), value.end());

        ListNode dummy(0);
        ListNode* curr = &dummy;

        for(auto it: value){
            curr->next = new ListNode(it);
            curr = curr->next;
        }

        return dummy.next;
    }
};
