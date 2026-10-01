class Solution {
public:

    int getLength(ListNode* head) {
        int length = 0;

        while (head) {
            length++;
            head = head->next;
        }

        return length;
    }

    ListNode* deleteNode(ListNode* head, int index) {

        // Delete head
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* curr = head;

        // Go to node before target
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        // Delete target
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = getLength(head);

        int index = length - n;

        return deleteNode(head, index);
    }
};