
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int nodePlace = count - n;

        // If the head itself must be removed
        if (nodePlace == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* prev = head;
        temp = head->next;

        while (temp != NULL) {
            nodePlace--;

            if (nodePlace == 0) {
                prev->next = temp->next;
                delete temp;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
