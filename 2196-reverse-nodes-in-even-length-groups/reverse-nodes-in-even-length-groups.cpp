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
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        // Dummy node helps us easily connect the reversed groups
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Expected size of the current group: 1, 2, 3, 4...
        int groupsize = 1;

        // Node before the current group
        ListNode* groupprev = dummy;

        // First node of the current group
        ListNode* groupstart = head;

        while (groupstart != NULL) {

            int actualsize = 0;

            // Find the last node of the current group
            ListNode* groupend = groupstart;

            while (groupend && actualsize < groupsize) {
                actualsize++;

                // Stop if we reached the expected group size
                // OR reached the last node of the list
                if (actualsize == groupsize || !groupend->next) {
                    break;
                }

                groupend = groupend->next;
            }

            // First node of the next group
            ListNode* groupnext = groupend->next;

            // Reverse only if the actual group size is even
            if (actualsize % 2 == 0) {

                // Start prev from the next group so that
                // reversed group connects directly to it
                ListNode* prev = groupnext;
                ListNode* curr = groupstart;

                // Reverse exactly 'actualsize' nodes
                while (actualsize--) {

                    ListNode* getnext = curr->next;

                    // Reverse current node's link
                    curr->next = prev;

                    prev = curr;
                    curr = getnext;
                }

                // Connect previous group to the new first node
                // of the reversed group
                groupprev->next = prev;

                // Original groupstart is now the last node
                // of the reversed group
                groupprev = groupstart;
            }

            else {
                // Odd-sized group is not reversed,
                // so groupend remains the last processed node
                groupprev = groupend;
            }

            // Move to the next group
            groupstart = groupnext;

            // Increase expected group size
            groupsize++;
        }

        return dummy->next;
    }
};