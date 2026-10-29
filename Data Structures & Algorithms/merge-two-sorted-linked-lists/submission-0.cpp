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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> nums;

        while(list1 != NULL){
            nums.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2 != NULL){
            nums.push_back(list2->val);
            list2 = list2->next;
        }

        sort(nums.begin(), nums.end());

        ListNode dummy(0);
        ListNode* ptr = &dummy;

        for(auto it: nums){
            ptr->next = new ListNode(it);
            ptr = ptr -> next;
        }

        return dummy.next;
    }
};
