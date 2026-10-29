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
    ListNode* reverseList(ListNode* head) {
        vector<int> nums;

        ListNode* temp = head;

        while (temp != NULL) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        reverse(nums.begin(), nums.end());

        ListNode dummy(0);
        ListNode* ptr = &dummy;

        for (int num : nums) {
            ptr->next = new ListNode(num);
            ptr = ptr->next;
        }

        return dummy.next;
    }
};
