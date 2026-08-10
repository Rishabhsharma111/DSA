class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // Step 1: Find length and tail
        int length = 1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            length++;
        }

        // Step 2: Reduce unnecessary rotations
        k = k % length;

        if(k == 0)
            return head;

        // Step 3: Make the list circular
        tail->next = head;

        // Step 4: Find the new tail
        int steps = length - k - 1;
        ListNode* newTail = head;

        while(steps--){
            newTail = newTail->next;
        }

        // Step 5: New head
        ListNode* newHead = newTail->next;

        // Step 6: Break the circle
        newTail->next = NULL;

        return newHead;
    }
};