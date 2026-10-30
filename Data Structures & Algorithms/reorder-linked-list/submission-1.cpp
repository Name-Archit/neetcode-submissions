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
        if (head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode* ansLeft = head;
        ListNode* ansRight = prev;

        while (ansRight != NULL) {
            ListNode* tempLeft = ansLeft->next;
            ListNode* tempRight = ansRight->next;

            ansLeft->next = ansRight;
            ansRight->next = tempLeft;

            ansLeft = tempLeft;
            ansRight = tempRight;
        }
    }
};
