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
    void reorderList(ListNode* head) {
        vector<int> value;

        ListNode* temp = head;

        while(temp != NULL){
            value.push_back(temp->val);
            temp = temp->next;
        }

        int left = 0;
        int right = value.size() - 1;

        
        ListNode* curr = head;
        int entry = 0;

        while(left <= right){
            if(entry == 0){
                curr->val = value[left];
                entry = 1;
                left++;
            }
            else{
                curr->val = value[right];
                entry = 0;
                right--;
            }
            curr = curr->next;            
        }
        
        return;
    }
};
