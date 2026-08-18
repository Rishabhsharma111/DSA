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

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {

        // Dummy node makes merging easier
        ListNode* dummy = new ListNode(0);

        ListNode* curr = dummy;

        // Compare nodes from both lists
        while(left && right) {

            if(left->val <= right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        // Attach remaining nodes
        if(left)
            curr->next = left;
        else
            curr->next = right;

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        // Base case:
        // Empty list or one node is already sorted
        if(head == NULL || head->next == NULL)
            return head;


        // Find middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }


        // Divide the list into two halves
        ListNode* second = slow->next;

        // Break the connection
        slow->next = NULL;


        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);


        // Merge the sorted halves
        return merge(left, right);
    }
};