
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* prev = head;

        while (prev != nullptr) {
            size++;
            prev = prev->next;
        }

        if (size == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int position = size - n - 1;
        ListNode* curr = head;

        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }

        ListNode* nodeToDelete = curr->next;
        curr->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};
